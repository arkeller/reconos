----------------------------------------------------------------------------------
-- Company: 
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

library reconos_v2_01_a;
use reconos_v2_01_a.reconos_pkg.all;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity hwt_write is
	
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

architecture Behavioral of hwt_write is

	attribute keep_hierarchy               : string;
	attribute keep_hierarchy of Behavioral : architecture is "true";
	
	constant C_MBOX_GET : std_logic_vector(0 to 31) := X"00000000";
	constant C_MBOX_PUT : std_logic_vector(0 to 31) := X"00000001";
	
	type t_state is (
		STATE_INIT,
		STATE_GET_ADDR,
		STATE_SAVE_PTR,
		STATE_READ,
		STATE_WRITE,
		STATE_SEND_1,
		STATE_SEND_2,
		STATE_DONE
	);

	signal state : t_state;
	signal sum   : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
	signal data  : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
	signal addr  : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
	signal ptr   : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
	signal counter : std_logic_vector(24 downto 0);
	signal cycles : std_logic_vector(31 downto 0);
	signal cycles_read : std_logic_vector(31 downto 0);
	signal timer_reset : std_logic;
	signal run : std_logic;
begin
	
	-- burst ram interface is not used
	o_RAMAddr <= (others => '0');
	o_RAMData <= (others => '0');
	o_RAMWE   <= '0';
	o_RAMClk  <= clk;
	
	timer_proc : process(clk, timer_reset, run)
	begin
		if timer_reset = '1' then
			cycles <= (others => '0');
		elsif run = '1' and rising_edge(clk) then
			cycles <= cycles + 1;
		end if;
	end process;
	
	state_proc : process(clk, reset)
		variable done : boolean;
		variable success : boolean;
	begin
		if reset = '1' then
			reconos_reset(o_osif, i_osif);
			state <= STATE_INIT;
			data <= (others => '0');
			ptr <= (others => '0');
			addr <= (others => '0');
			counter <= (others => '0');
			timer_reset <= '1';
			run <= '0';
		elsif rising_edge(clk) then
			
			reconos_begin(o_osif, i_osif);
			
			if reconos_ready(i_osif) then
				case state is
				
				when STATE_INIT =>
					timer_reset <= '1';
					sum <= (others => '0');
					data <= (others => '0');
					counter <= (others => '0');
					state <= STATE_GET_ADDR;
				
				when STATE_GET_ADDR =>
					reconos_mbox_get_s(done, success, o_osif, i_osif, C_MBOX_GET, addr);
					if done and success then
						timer_reset <= '0';
						state <= STATE_SAVE_PTR;
					end if;
					
				when STATE_SAVE_PTR =>
					ptr <= addr;
					reconos_read_s(done, o_osif, i_osif, addr, data); -- create TLB entry
					if done then
						run <= '1';
						state <= STATE_READ;
					end if;
					
				when STATE_READ =>
					if counter > 127 then
						ptr <= addr;
						cycles_read <= cycles;
						state <= STATE_WRITE;
					else
						reconos_read_burst(done, o_osif, i_osif, X"00000000", ptr);
						if done then
							ptr <= ptr + 32;
							counter <= counter + 1;
						end if;
					end if;
					
				when STATE_WRITE =>
					if counter > 255 then
						state <= STATE_SEND_1;
						run <= '0';
					else 
						reconos_write_burst(done, o_osif, i_osif, X"00000000",ptr);
						if done then
							ptr <= ptr + 32;
							counter <= counter + 1;
						end if;
					end if;
					
				when STATE_SEND_1 =>
					reconos_mbox_put(done, success, o_osif, i_osif, C_MBOX_PUT, cycles_read);
					if done then state <= STATE_SEND_2; end if;
				
				when STATE_SEND_2 =>
					reconos_mbox_put(done, success, o_osif, i_osif, C_MBOX_PUT, cycles);
					if done then state <= STATE_DONE; end if;
					
				when STATE_DONE =>
					state <= STATE_INIT;
									
				end case;
			end if;
		end if;
	end process;
end Behavioral;

