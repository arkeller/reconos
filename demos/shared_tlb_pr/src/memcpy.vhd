----------------------------------------------------------------------------------
-- Company: 
library IEEE;
use IEEE.STD_LOGIC_1164.all;
--use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;
use IEEE.NUMERIC_STD.all;

library reconos_v2_01_a;
use reconos_v2_01_a.reconos_pkg.all;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity memcpy is
	
	generic (
		C_BURST_AWIDTH : integer := 12;
		C_BURST_DWIDTH : integer := 32
	);
	
	port (
		clk    : in  std_logic;
		reset  : in  std_logic;
		i_osif : in  osif_os2task_t;
		o_osif : out osif_task2os_t;
		
		-- burst ram interface
		o_RAMAddr : out std_logic_vector(0 to C_BURST_AWIDTH-1);
		o_RAMData : out std_logic_vector(0 to C_BURST_DWIDTH-1);
		i_RAMData : in  std_logic_vector(0 to C_BURST_DWIDTH-1);
		o_RAMWE   : out std_logic;
		o_RAMClk  : out std_logic
	);
	
end entity;

architecture Behavioral of memcpy is

	attribute keep_hierarchy               : string;
	attribute keep_hierarchy of Behavioral : architecture is "true";
	
	constant C_MBOX_HANDLE_SW_HW  : std_logic_vector(0 to 31) := X"00000000";
	constant C_MBOX_HANDLE_HW_SW : std_logic_vector(0 to 31) := X"00000001";

	type t_state is (STATE_INIT, STATE_INIT_2, STATE_INIT_3, STATE_RX_IDLE, STATE_TX_IDLE, 
					STATE_SEND_TO_SW, STATE_SEND_NR_FRAMES, STATE_READ_FROM_SW);

	signal os_sync_state : t_state;
begin
	
	-- burst ram interface is not used
	o_RAMAddr <= (others => '0');
	o_RAMData <= (others => '0');
	o_RAMWE   <= '0';
	o_RAMClk  <= clk;
	
	
	state_proc : process(clk, reset)
		variable done : boolean;
		variable success : boolean;

		variable tx_system_address 		: std_logic_vector(0 to C_OSIF_DATA_WIDTH - 1);
    	variable rx_system_address 		: std_logic_vector(0 to C_OSIF_DATA_WIDTH - 1);
    	variable default_idp 			: std_logic_vector(0 to C_OSIF_DATA_WIDTH - 1);
	
		variable tx_packet_len 			: std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
		variable rx_packet_len 			: std_logic_vector(0 to C_BURST_DWIDTH - 1);

		variable local_addr				: std_logic_vector(0 to C_BURST_AWIDTH - 1 + 3); --we address bytes and not words

	--	variable padding				: std_logic_vector(0 to C_OSIF_DATA_WIDTH - 1 - (C_BURST_AWIDTH - 1 + 3) - 1);
		variable count 					: natural;

	begin
		if reset = '1' then
			reconos_reset(o_osif, i_osif);
			os_sync_state <= STATE_INIT;
		elsif rising_edge(clk) then
			
			reconos_begin(o_osif, i_osif);
			
			if reconos_ready(i_osif) then
				case os_sync_state is
				
				-- default IDP to send data to
				when STATE_INIT =>
					reconos_get_init_data(done, o_osif, i_osif, default_idp);
		    		if done then
						os_sync_state <= STATE_INIT_2;
		    		end if;
					count := 0;
					local_addr := X"00000000";
				-- we write in a Ring buffer, tx_system_address is the ptr to the transmit ring
				when STATE_INIT_2 => 
	    			reconos_mbox_get(done, success, o_osif, i_osif, C_MBOX_HANDLE_SW_HW, tx_system_address);
	    			if done and success then
						os_sync_state <= STATE_INIT_3;
		    		end if;
				when STATE_INIT_3 => 
	    			reconos_mbox_get(done, success, o_osif, i_osif, C_MBOX_HANDLE_SW_HW, rx_system_address);
	    			if done and success then
						os_sync_state <= STATE_RX_IDLE;
		    		end if;

				when STATE_RX_IDLE => 
		   			os_sync_state <= STATE_TX_IDLE;

				when STATE_TX_IDLE =>
		    		reconos_mbox_tryget(done, success, o_osif, i_osif, C_MBOX_HANDLE_SW_HW, tx_packet_len);
		    		if done and success then
						os_sync_state <= STATE_READ_FROM_SW;
						rx_packet_len := tx_packet_len;
		    		end if;
		    		if done and not success then
						os_sync_state <= STATE_RX_IDLE;
		   			end if;

				when STATE_READ_FROM_SW =>
		    		reconos_read_burst(done, o_osif, i_osif, std_logic_vector(unsigned(local_addr) +  count), 
		    							std_logic_vector(unsigned(tx_system_address) + count));
		    		if done then
						count := count + 128;
						if count >= unsigned(tx_packet_len) then
			    			os_sync_state <= STATE_SEND_TO_SW;
			    			count := 0;
			    			tx_system_address := std_logic_vector(unsigned(tx_system_address) + unsigned(tx_packet_len));
						end if;
		  			end if;

				when STATE_SEND_TO_SW => 
				    reconos_write_burst(done, o_osif, i_osif, std_logic_vector(unsigned(local_addr) + count), 
		    							std_logic_vector(unsigned(rx_system_address) + count));
		    		if done then
						count := count + 128;
						if count >= rx_packet_len then
			    			os_sync_state <=  STATE_SEND_NR_FRAMES;
			    			count := 0;
			    			rx_system_address := std_logic_vector(unsigned(rx_system_address) + 128);
						end if;
		    		end if;

				when STATE_SEND_NR_FRAMES => 
		    		reconos_mbox_put(done, success, o_osif, i_osif, C_MBOX_HANDLE_HW_SW, rx_packet_len);
		    		if done then 
						os_sync_state <= STATE_RX_IDLE;
		    		end if;


--				when STATE_GET_ADDR =>
--					reconos_mbox_get_s(done, success, o_osif, i_osif, C_MBOX_GET, addr);
--					if done and success then
--						timer_reset <= '0';
--						state <= STATE_SAVE_PTR;
--					end if;
					
---do we need this state?
--				when STATE_SAVE_PTR =>
--					ptr <= addr;
--					reconos_read_s(done, o_osif, i_osif, addr, data); -- create TLB entry
--					if done then
--						run <= '1';
--						state <= STATE_READ;
--					end if;
					
--				when STATE_READ =>
				--	if counter > 127 then
				--		ptr <= addr;
				--		cycles_read <= cycles;
				--		state <= STATE_WRITE;
				--	else
--						reconos_read_burst(done, o_osif, i_osif, X"00000000", ptr);
--						if done then
--							ptr <= ptr + 128;
			--			counter <= counter + 1;
--							state <= STATE_WRITE;
--						end if;
				--	end if;
					
--				when STATE_WRITE =>
				--	if counter > 255 then
				--		state <= STATE_SEND_1;
				--		run <= '0';
				--	else 
--						reconos_write_burst(done, o_osif, i_osif, X"00000000",ptr);
--						if done then
				--			ptr <= ptr + 32;
				--			counter <= counter + 1;
--							state <= STATE_SEND_1;
--						end if;
				--	end if;
					
--				when STATE_SEND_1 =>
--					reconos_mbox_put(done, success, o_osif, i_osif, C_MBOX_PUT, cycles_read);
--					if done then state <= STATE_SEND_2; end if;
				
--				when STATE_SEND_2 =>
--					reconos_mbox_put(done, success, o_osif, i_osif, C_MBOX_PUT, cycles);
--					if done then state <= STATE_DONE; end if;
					
--				when STATE_DONE =>
--					state <= STATE_INIT;
									
				end case;
			end if;
		end if;
	end process;
end Behavioral;

