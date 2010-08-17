--!
--! \file mem_plb46.vhd
--!
--! Memory bus interface for PLB v46 (64 bit)
--!
--! \author     Enno Luebbers   <enno.luebbers@upb.de>
--! \date       15.12.2008
--
-----------------------------------------------------------------------------
-- %%%RECONOS_COPYRIGHT_BEGIN%%%
-- %%%RECONOS_COPYRIGHT_END%%%
-----------------------------------------------------------------------------
--
-- Major Changes:
--
-- 15.12.2008   Enno Luebbers   File created (adapted from Xilinx-generated
--                              user_logic.vhd).

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

library proc_common_v2_00_a;
use proc_common_v2_00_a.proc_common_pkg.all;
use proc_common_v2_00_a.srl_fifo_f;

------------------------------------------------------------------------------
-- Entity section
------------------------------------------------------------------------------
-- Definition of Generics:
--   C_SLV_AWIDTH                 -- Slave interface address bus width
--   C_SLV_DWIDTH                 -- Slave interface data bus width
--   C_MST_AWIDTH                 -- Master interface address bus width
--   C_MST_DWIDTH                 -- Master interface data bus width
--   C_NUM_REG                    -- Number of software accessible registers
--   C_NUM_MEM                    -- Number of memory spaces
--
-- Definition of Ports:
--   Bus2IP_Clk                   -- Bus to IP clock
--   Bus2IP_Reset                 -- Bus to IP reset
--   Bus2IP_Addr                  -- Bus to IP address bus
--   Bus2IP_CS                    -- Bus to IP chip select for user logic memory selection
--   Bus2IP_RNW                   -- Bus to IP read/not write
--   Bus2IP_Data                  -- Bus to IP data bus
--   Bus2IP_BE                    -- Bus to IP byte enables
--   Bus2IP_RdCE                  -- Bus to IP read chip enable
--   Bus2IP_WrCE                  -- Bus to IP write chip enable
--   Bus2IP_Burst                 -- Bus to IP burst-mode qualifier
--   Bus2IP_BurstLength           -- Bus to IP burst length
--   Bus2IP_RdReq                 -- Bus to IP read request
--   Bus2IP_WrReq                 -- Bus to IP write request
--   IP2Bus_AddrAck               -- IP to Bus address acknowledgement
--   IP2Bus_Data                  -- IP to Bus data bus
--   IP2Bus_RdAck                 -- IP to Bus read transfer acknowledgement
--   IP2Bus_WrAck                 -- IP to Bus write transfer acknowledgement
--   IP2Bus_Error                 -- IP to Bus error response
--   IP2Bus_MstRd_Req             -- IP to Bus master read request
--   IP2Bus_MstWr_Req             -- IP to Bus master write request
--   IP2Bus_Mst_Addr              -- IP to Bus master address bus
--   IP2Bus_Mst_BE                -- IP to Bus master byte enables
--   IP2Bus_Mst_Length            -- IP to Bus master transfer length
--   IP2Bus_Mst_Type              -- IP to Bus master transfer type
--   IP2Bus_Mst_Lock              -- IP to Bus master lock
--   IP2Bus_Mst_Reset             -- IP to Bus master reset
--   Bus2IP_Mst_CmdAck            -- Bus to IP master command acknowledgement
--   Bus2IP_Mst_Cmplt             -- Bus to IP master transfer completion
--   Bus2IP_Mst_Error             -- Bus to IP master error response
--   Bus2IP_Mst_Rearbitrate       -- Bus to IP master re-arbitrate
--   Bus2IP_Mst_Cmd_Timeout       -- Bus to IP master command timeout
--   Bus2IP_MstRd_d               -- Bus to IP master read data bus
--   Bus2IP_MstRd_rem             -- Bus to IP master read remainder
--   Bus2IP_MstRd_sof_n           -- Bus to IP master read start of frame
--   Bus2IP_MstRd_eof_n           -- Bus to IP master read end of frame
--   Bus2IP_MstRd_src_rdy_n       -- Bus to IP master read source ready
--   Bus2IP_MstRd_src_dsc_n       -- Bus to IP master read source discontinue
--   IP2Bus_MstRd_dst_rdy_n       -- IP to Bus master read destination ready
--   IP2Bus_MstRd_dst_dsc_n       -- IP to Bus master read destination discontinue
--   IP2Bus_MstWr_d               -- IP to Bus master write data bus
--   IP2Bus_MstWr_rem             -- IP to Bus master write remainder
--   IP2Bus_MstWr_sof_n           -- IP to Bus master write start of frame
--   IP2Bus_MstWr_eof_n           -- IP to Bus master write end of frame
--   IP2Bus_MstWr_src_rdy_n       -- IP to Bus master write source ready
--   IP2Bus_MstWr_src_dsc_n       -- IP to Bus master write source discontinue
--   Bus2IP_MstWr_dst_rdy_n       -- Bus to IP master write destination ready
--   Bus2IP_MstWr_dst_dsc_n       -- Bus to IP master write destination discontinue
------------------------------------------------------------------------------

entity mem_plb46 is
  generic
  (
    -- ADD USER GENERICS BELOW THIS LINE ---------------
    --USER generics added here
    -- ADD USER GENERICS ABOVE THIS LINE ---------------

    -- DO NOT EDIT BELOW THIS LINE ---------------------
    -- Bus protocol parameters, do not add to or delete
    C_SLV_AWIDTH                   : integer              := 32;
    C_SLV_DWIDTH                   : integer              := 64;
    C_MST_AWIDTH                   : integer              := 32;
    C_MST_DWIDTH                   : integer              := 64;
    C_NUM_REG                      : integer              := 2;
    C_NUM_MEM                      : integer              := 1;
    C_BURST_AWIDTH                 : integer              := 14;  -- 2048 x 64 Bit = 16384 Bytes = 2^14 Bytes
    C_BURST_DWIDTH                 : integer              := 32;  
    C_BURST_BASEADDR               : std_logic_vector     := X"00004000"  -- system memory base address for burst ram access
  );
  port
  (
    clk              : in std_logic;
    reset            : in std_logic;

    -- data interface           ---------------------------

    -- burst mem interface
    o_burstAddr : out std_logic_vector(0 to C_BURST_AWIDTH-1);
    o_burstData : out std_logic_vector(0 to C_BURST_DWIDTH-1);
    i_burstData : in  std_logic_vector(0 to C_BURST_DWIDTH-1);
    o_burstWE   : out std_logic;
    o_burstBE   : out std_logic_vector(0 to C_BURST_DWIDTH/8-1);

    -- single word data input/output
    i_singleData : in  std_logic_vector(0 to C_MST_DWIDTH-1);
    -- osif2bus 
    o_singleData : out std_logic_vector(0 to C_MST_DWIDTH-1);
    -- bus2osif

    -- control interface        ------------------------

    -- addresses for master transfers
    i_localAddr  : in std_logic_vector(0 to C_MST_AWIDTH-1);
    i_targetAddr : in std_logic_vector(0 to C_MST_AWIDTH-1);

    -- single word transfer requests
    i_singleRdReq : in std_logic;
    i_singleWrReq : in std_logic;

    -- burst transfer requests
    i_burstRdReq : in std_logic;
    i_burstWrReq : in std_logic;
    i_burstLen   : in std_logic_vector(0 to 4);  -- number of burst beats (n x 64 bits)

    -- status outputs
    o_busy   : out std_logic;
    o_rdDone : out std_logic;
    o_wrDone : out std_logic;


    -- PLBv34 bus interface     -----------------------------------------
    Bus2IP_Clk                     : in  std_logic;
    Bus2IP_Reset                   : in  std_logic;
    Bus2IP_Addr                    : in  std_logic_vector(0 to C_SLV_AWIDTH-1);
    Bus2IP_CS                      : in  std_logic_vector(0 to C_NUM_MEM-1);
    Bus2IP_RNW                     : in  std_logic;
    Bus2IP_Data                    : in  std_logic_vector(0 to C_SLV_DWIDTH-1);
    Bus2IP_BE                      : in  std_logic_vector(0 to C_SLV_DWIDTH/8-1);
    Bus2IP_RdCE                    : in  std_logic_vector(0 to C_NUM_REG-1);
    Bus2IP_WrCE                    : in  std_logic_vector(0 to C_NUM_REG-1);
    Bus2IP_Burst                   : in  std_logic;
    Bus2IP_BurstLength             : in  std_logic_vector(0 to 8);
    Bus2IP_RdReq                   : in  std_logic;
    Bus2IP_WrReq                   : in  std_logic;
    IP2Bus_AddrAck                 : out std_logic;
    IP2Bus_Data                    : out std_logic_vector(0 to C_SLV_DWIDTH-1);
    IP2Bus_RdAck                   : out std_logic;
    IP2Bus_WrAck                   : out std_logic;
    IP2Bus_Error                   : out std_logic;
    IP2Bus_MstRd_Req               : out std_logic;
    IP2Bus_MstWr_Req               : out std_logic;
    IP2Bus_Mst_Addr                : out std_logic_vector(0 to C_MST_AWIDTH-1);
    IP2Bus_Mst_BE                  : out std_logic_vector(0 to C_MST_DWIDTH/8-1);
    IP2Bus_Mst_Length              : out std_logic_vector(0 to 11);
    IP2Bus_Mst_Type                : out std_logic;
    IP2Bus_Mst_Lock                : out std_logic;
    IP2Bus_Mst_Reset               : out std_logic;
    Bus2IP_Mst_CmdAck              : in  std_logic;
    Bus2IP_Mst_Cmplt               : in  std_logic;
    Bus2IP_Mst_Error               : in  std_logic;
    Bus2IP_Mst_Rearbitrate         : in  std_logic;
    Bus2IP_Mst_Cmd_Timeout         : in  std_logic;
    Bus2IP_MstRd_d                 : in  std_logic_vector(0 to C_MST_DWIDTH-1);
    Bus2IP_MstRd_rem               : in  std_logic_vector(0 to C_MST_DWIDTH/8-1);
    Bus2IP_MstRd_sof_n             : in  std_logic;
    Bus2IP_MstRd_eof_n             : in  std_logic;
    Bus2IP_MstRd_src_rdy_n         : in  std_logic;
    Bus2IP_MstRd_src_dsc_n         : in  std_logic;
    IP2Bus_MstRd_dst_rdy_n         : out std_logic;
    IP2Bus_MstRd_dst_dsc_n         : out std_logic;
    IP2Bus_MstWr_d                 : out std_logic_vector(0 to C_MST_DWIDTH-1);
    IP2Bus_MstWr_rem               : out std_logic_vector(0 to C_MST_DWIDTH/8-1);
    IP2Bus_MstWr_sof_n             : out std_logic;
    IP2Bus_MstWr_eof_n             : out std_logic;
    IP2Bus_MstWr_src_rdy_n         : out std_logic;
    IP2Bus_MstWr_src_dsc_n         : out std_logic;
    Bus2IP_MstWr_dst_rdy_n         : in  std_logic;
    Bus2IP_MstWr_dst_dsc_n         : in  std_logic
    -- DO NOT EDIT ABOVE THIS LINE ---------------------
  );

  attribute SIGIS : string;
  attribute SIGIS of Bus2IP_Clk    : signal is "CLK";
  attribute SIGIS of Bus2IP_Reset  : signal is "RST";
  attribute SIGIS of IP2Bus_Mst_Reset: signal is "RST";

end entity mem_plb46;

------------------------------------------------------------------------------
-- Architecture section
------------------------------------------------------------------------------

architecture IMP of mem_plb46 is

  ------------------------------------------
  -- Signals for user logic master
  ------------------------------------------
  -- signals for master model control/status registers write/read
  signal mst_ip2bus_data                : std_logic_vector(0 to C_SLV_DWIDTH-1);
  signal mst_reg_write_req              : std_logic;
  signal mst_reg_read_req               : std_logic;
  signal mst_reg_write_sel              : std_logic_vector(0 to 1);
  signal mst_reg_read_sel               : std_logic_vector(0 to 1);
  signal mst_write_ack                  : std_logic;
  signal mst_read_ack                   : std_logic;
  -- signals for master model control/status registers
  type BYTE_REG_TYPE is array(0 to 15) of std_logic_vector(0 to 7);
  signal mst_reg                        : BYTE_REG_TYPE;
  signal mst_byte_we                    : std_logic_vector(0 to 15);
  signal mst_cntl_rd_req                : std_logic;
  signal mst_cntl_wr_req                : std_logic;
  signal mst_cntl_bus_lock              : std_logic;
  signal mst_cntl_burst                 : std_logic;
  signal mst_ip2bus_addr                : std_logic_vector(0 to C_MST_AWIDTH-1);
  signal mst_xfer_length                : std_logic_vector(0 to 11);
  signal mst_ip2bus_be                  : std_logic_vector(0 to 15);
  signal mst_go                         : std_logic;
  -- signals for master model command interface state machine
  type CMD_CNTL_SM_TYPE is (CMD_IDLE, CMD_RUN, CMD_WAIT_FOR_DATA, CMD_DONE);
  signal mst_cmd_sm_state               : CMD_CNTL_SM_TYPE;
  signal mst_cmd_sm_set_done            : std_logic;
  signal mst_cmd_sm_set_error           : std_logic;
  signal mst_cmd_sm_set_timeout         : std_logic;
  signal mst_cmd_sm_busy                : std_logic;
  signal mst_cmd_sm_clr_go              : std_logic;
  signal mst_cmd_sm_rd_req              : std_logic;
  signal mst_cmd_sm_wr_req              : std_logic;
  signal mst_cmd_sm_reset               : std_logic;
  signal mst_cmd_sm_bus_lock            : std_logic;
  signal mst_cmd_sm_ip2bus_addr         : std_logic_vector(0 to C_MST_AWIDTH-1);
  signal mst_cmd_sm_ip2bus_be           : std_logic_vector(0 to C_MST_DWIDTH/8-1);
  signal mst_cmd_sm_xfer_type           : std_logic;
  signal mst_cmd_sm_xfer_length         : std_logic_vector(0 to 11);
  signal mst_cmd_sm_start_rd_llink      : std_logic;
  signal mst_cmd_sm_start_wr_llink      : std_logic;
  -- signals for master model read locallink interface state machine
  type RD_LLINK_SM_TYPE is (LLRD_IDLE, LLRD_GO);
  signal mst_llrd_sm_state              : RD_LLINK_SM_TYPE;
  signal mst_llrd_sm_dst_rdy            : std_logic;
  -- signals for master model write locallink interface state machine
  type WR_LLINK_SM_TYPE is (LLWR_IDLE, LLWR_SNGL_INIT, LLWR_SNGL, LLWR_BRST_INIT, LLWR_BRST, LLWR_BRST_LAST_BEAT);
  signal mst_llwr_sm_state              : WR_LLINK_SM_TYPE;
  signal mst_llwr_sm_src_rdy            : std_logic;
  signal mst_llwr_sm_sof                : std_logic;
  signal mst_llwr_sm_eof                : std_logic;
  signal mst_llwr_byte_cnt              : integer;
  signal mst_fifo_valid_write_xfer      : std_logic;
  signal mst_fifo_valid_read_xfer       : std_logic;

  ------------------------------------------
  -- Signals for user logic memory space example
  ------------------------------------------
  type BYTE_RAM_TYPE is array (0 to 255) of std_logic_vector(0 to 7);
  type DO_TYPE is array (0 to C_NUM_MEM-1) of std_logic_vector(0 to C_SLV_DWIDTH-1);
  signal mem_data_out                   : DO_TYPE;
  signal mem_address                    : std_logic_vector(0 to 7);
  signal mem_select                     : std_logic_vector(0 to 0);
  signal mem_read_enable                : std_logic;
  signal mem_ip2bus_data                : std_logic_vector(0 to C_SLV_DWIDTH-1);
  signal mem_read_ack_dly1              : std_logic;
  signal mem_read_ack                   : std_logic;
  signal mem_write_ack                  : std_logic;

begin

-------------------------------------------------------------------
-- PLB master state machine
--
-- FIXME: are the mst_sm_*_req signals set right, or does this
-- cause too complicated logic?
-------------------------------------------------------------------
    plb_master : process(clk, reset)

    begin
        if reset = '1' then
            plb_master_state <= IDLE;
            mst_cmd_sm_rd_req <= '0';
            mst_cmd_sm_wr_req <= '0';
            o_read_done      <= '0';    -- FIXME: could this be just a o_done?
            o_write_done     <= '0';
            mst_cmd_sm_ip2bus_be     <= "00000000";  -- 0 Bit
            mst_cmd_sm_ip2bus_addr    <= (others => '0');

        elsif rising_edge(clk) then

            o_read_done  <= '0';
            o_write_done <= '0';

            case plb_master_state is
                when IDLE =>
                    if i_read_req = '1' then
                        plb_master_state <= READ;
                        mst_cmd_sm_rd_req    <= '1';
                        -- single
                        if i_target_addr(29) = '0' then  -- align word access
                            mst_cmd_sm_ip2bus_be <= "11110000";  -- 32 Bit
                        else
                            mst_cmd_sm_ip2bus_be <= "00001111";  -- 32 Bit
                        end if;
                        IP2Bus_Mst_Type <= '0';       -- single beat


                    elsif i_write_req = '1' then
                        plb_master_state <= WRITE;
                        mst_sm_wr_req    <= '1';
                        -- single
                        if i_target_addr(29) = '0' then  -- align word access
                            IP2Bus_MstBE <= "11110000";  -- 32 Bit
                        else
                            IP2Bus_MstBE <= "00001111";  -- 32 Bit
                        end if;
                        IP2Bus_MstBurst  <= '0';  -- no burst
                        IP2Bus_MstNum    <= "00001";  -- single beat transaction
                    elsif i_burst_read_req = '1' then
                        plb_master_state <= READ;
                        mst_sm_rd_req    <= '1';
                        -- burst
                        IP2Bus_MstBE     <= "11111111";  -- 64 Bit
                        IP2Bus_MstBurst  <= '1';  -- burst
--            IP2Bus_MstNum    <= "11111";  -- 16x64 Bit burst
                        IP2Bus_MstNum    <= i_burst_length;  -- n x 64 Bit burst, max 16
                    elsif i_burst_write_req = '1' then
                        plb_master_state <= WRITE;
                        mst_sm_wr_req    <= '1';
                        -- burst
                        IP2Bus_MstBE     <= "11111111";  -- 64 Bit
                        IP2Bus_MstBurst  <= '1';  -- burst
--            IP2Bus_MstNum    <= "11111";  -- 16x64 Bit burst
                        IP2Bus_MstNum    <= i_burst_length;  -- n x 64 Bit burst, max 16
                    end if;

                when READ =>
                    if Bus2IP_MstLastAck = '1' or           -- on completion or
                                Bus2IP_MstTimeout = '1' or  -- on timeout or
                                Bus2IP_MstError = '1' then  -- on error
                        o_read_done      <= '1';                      -- finish transaction
                        mst_sm_rd_req    <= '0';
                        plb_master_state <= IDLE;
                    end if;

                when WRITE =>
                    if Bus2IP_MstLastAck = '1' or                     -- on completion or
                                Bus2IP_MstTimeout = '1' or  -- on timeout or
                                Bus2IP_MstError = '1' then		-- on error
                        o_write_done     <= '1';
                        mst_sm_wr_req    <= '0';			-- finish transaction
                        plb_master_state <= IDLE;
                    end if;
                    
                when others =>
                    plb_master_state <= IDLE;
                    
            end case;
        end if;
    end process;



  -- user logic master command interface assignments
  IP2Bus_MstRd_Req  <= mst_cmd_sm_rd_req;
  IP2Bus_MstWr_Req  <= mst_cmd_sm_wr_req;
  IP2Bus_Mst_Addr   <= mst_cmd_sm_ip2bus_addr;
  IP2Bus_Mst_BE     <= mst_cmd_sm_ip2bus_be;
  IP2Bus_Mst_Type   <= mst_cmd_sm_xfer_type;
  IP2Bus_Mst_Length <= mst_cmd_sm_xfer_length;
  IP2Bus_Mst_Lock   <= mst_cmd_sm_bus_lock;
  IP2Bus_Mst_Reset  <= mst_cmd_sm_reset;

  --implement master command interface state machine
  MASTER_CMD_SM_PROC : process( Bus2IP_Clk ) is
  begin

    if ( Bus2IP_Clk'event and Bus2IP_Clk = '1' ) then
      if ( Bus2IP_Reset = '1' ) then

        -- reset condition
        mst_cmd_sm_state          <= CMD_IDLE;
        mst_cmd_sm_clr_go         <= '0';
        mst_cmd_sm_rd_req         <= '0';
        mst_cmd_sm_wr_req         <= '0';
        mst_cmd_sm_bus_lock       <= '0';
        mst_cmd_sm_reset          <= '0';
        mst_cmd_sm_ip2bus_addr    <= (others => '0');
        mst_cmd_sm_ip2bus_be      <= (others => '0');
        mst_cmd_sm_xfer_type      <= '0';
        mst_cmd_sm_xfer_length    <= (others => '0');
        mst_cmd_sm_set_done       <= '0';
        mst_cmd_sm_set_error      <= '0';
        mst_cmd_sm_set_timeout    <= '0';
        mst_cmd_sm_busy           <= '0';
        mst_cmd_sm_start_rd_llink <= '0';
        mst_cmd_sm_start_wr_llink <= '0';

      else

        -- default condition
        mst_cmd_sm_clr_go         <= '0';
        mst_cmd_sm_rd_req         <= '0';
        mst_cmd_sm_wr_req         <= '0';
        mst_cmd_sm_bus_lock       <= '0';
        mst_cmd_sm_reset          <= '0';
        mst_cmd_sm_ip2bus_addr    <= (others => '0');
        mst_cmd_sm_ip2bus_be      <= (others => '0');
        mst_cmd_sm_xfer_type      <= '0';
        mst_cmd_sm_xfer_length    <= (others => '0');
        mst_cmd_sm_set_done       <= '0';
        mst_cmd_sm_set_error      <= '0';
        mst_cmd_sm_set_timeout    <= '0';
        mst_cmd_sm_busy           <= '1';
        mst_cmd_sm_start_rd_llink <= '0';
        mst_cmd_sm_start_wr_llink <= '0';

        -- state transition
        case mst_cmd_sm_state is

          when CMD_IDLE =>
            if ( mst_go = '1' ) then
              mst_cmd_sm_state  <= CMD_RUN;
              mst_cmd_sm_clr_go <= '1';
              if ( mst_cntl_rd_req = '1' ) then
                mst_cmd_sm_start_rd_llink <= '1';
              elsif ( mst_cntl_wr_req = '1' ) then
                mst_cmd_sm_start_wr_llink <= '1';
              end if;
            else
              mst_cmd_sm_state  <= CMD_IDLE;
              mst_cmd_sm_busy   <= '0';
            end if;

          when CMD_RUN =>
            if ( Bus2IP_Mst_CmdAck = '1' and Bus2IP_Mst_Cmplt = '0' ) then
              mst_cmd_sm_state <= CMD_WAIT_FOR_DATA;
            elsif ( Bus2IP_Mst_Cmplt = '1' ) then
              mst_cmd_sm_state <= CMD_DONE;
              if ( Bus2IP_Mst_Cmd_Timeout = '1' ) then
                -- PLB address phase timeout
                mst_cmd_sm_set_error   <= '1';
                mst_cmd_sm_set_timeout <= '1';
              elsif ( Bus2IP_Mst_Error = '1' ) then
                -- PLB data transfer error
                mst_cmd_sm_set_error   <= '1';
              end if;
            else
              mst_cmd_sm_state       <= CMD_RUN;
              mst_cmd_sm_rd_req      <= mst_cntl_rd_req;
              mst_cmd_sm_wr_req      <= mst_cntl_wr_req;
              mst_cmd_sm_ip2bus_addr <= mst_ip2bus_addr;
              mst_cmd_sm_ip2bus_be   <= mst_ip2bus_be(16-C_MST_DWIDTH/8 to 15);
              mst_cmd_sm_xfer_type   <= mst_cntl_burst;
              mst_cmd_sm_xfer_length <= mst_xfer_length;
              mst_cmd_sm_bus_lock    <= mst_cntl_bus_lock;
            end if;

          when CMD_WAIT_FOR_DATA =>
            if ( Bus2IP_Mst_Cmplt = '1' ) then
              mst_cmd_sm_state <= CMD_DONE;
            else
              mst_cmd_sm_state <= CMD_WAIT_FOR_DATA;
            end if;

          when CMD_DONE =>
            mst_cmd_sm_state    <= CMD_IDLE;
            mst_cmd_sm_set_done <= '1';
            mst_cmd_sm_busy     <= '0';

          when others =>
            mst_cmd_sm_state    <= CMD_IDLE;
            mst_cmd_sm_busy     <= '0';

        end case;

      end if;
    end if;

  end process MASTER_CMD_SM_PROC;

  -- user logic master read locallink interface assignments
  IP2Bus_MstRd_dst_rdy_n <= not(mst_llrd_sm_dst_rdy);
  IP2Bus_MstRd_dst_dsc_n <= '1'; -- do not throttle data

  -- implement a simple state machine to enable the
  -- read locallink interface to transfer data
  LLINK_RD_SM_PROCESS : process( Bus2IP_Clk ) is
  begin

    if ( Bus2IP_Clk'event and Bus2IP_Clk = '1' ) then
      if ( Bus2IP_Reset = '1' ) then

        -- reset condition
        mst_llrd_sm_state   <= LLRD_IDLE;
        mst_llrd_sm_dst_rdy <= '0';

      else

        -- default condition
        mst_llrd_sm_state   <= LLRD_IDLE;
        mst_llrd_sm_dst_rdy <= '0';

        -- state transition
        case mst_llrd_sm_state is

          when LLRD_IDLE =>
            if ( mst_cmd_sm_start_rd_llink = '1') then
              mst_llrd_sm_state <= LLRD_GO;
            else
              mst_llrd_sm_state <= LLRD_IDLE;
            end if;

          when LLRD_GO =>
            -- done, end of packet
            if ( mst_llrd_sm_dst_rdy    = '1' and
                 Bus2IP_MstRd_src_rdy_n = '0' and
                 Bus2IP_MstRd_eof_n     = '0' ) then
              mst_llrd_sm_state   <= LLRD_IDLE;
            -- not done yet, continue receiving data
            else
              mst_llrd_sm_state   <= LLRD_GO;
              mst_llrd_sm_dst_rdy <= '1';
            end if;

          when others =>
            mst_llrd_sm_state <= LLRD_IDLE;

        end case;

      end if;
    else
      null;
    end if;

  end process LLINK_RD_SM_PROCESS;

  -- user logic master write locallink interface assignments
  IP2Bus_MstWr_src_rdy_n <= not(mst_llwr_sm_src_rdy);
  IP2Bus_MstWr_src_dsc_n <= '1'; -- do not throttle data
  IP2Bus_MstWr_rem       <= (others => '0');
  IP2Bus_MstWr_sof_n     <= not(mst_llwr_sm_sof);
  IP2Bus_MstWr_eof_n     <= not(mst_llwr_sm_eof);

  -- implement a simple state machine to enable the
  -- write locallink interface to transfer data
  LLINK_WR_SM_PROC : process( Bus2IP_Clk ) is
    constant BYTES_PER_BEAT : integer := C_MST_DWIDTH/8;
  begin

    if ( Bus2IP_Clk'event and Bus2IP_Clk = '1' ) then
      if ( Bus2IP_Reset = '1' ) then

        -- reset condition
        mst_llwr_sm_state   <= LLWR_IDLE;
        mst_llwr_sm_src_rdy <= '0';
        mst_llwr_sm_sof     <= '0';
        mst_llwr_sm_eof     <= '0';
        mst_llwr_byte_cnt   <= 0;

      else

        -- default condition
        mst_llwr_sm_state   <= LLWR_IDLE;
        mst_llwr_sm_src_rdy <= '0';
        mst_llwr_sm_sof     <= '0';
        mst_llwr_sm_eof     <= '0';
        mst_llwr_byte_cnt   <= 0;

        -- state transition
        case mst_llwr_sm_state is

          when LLWR_IDLE =>
            if ( mst_cmd_sm_start_wr_llink = '1' and mst_cntl_burst = '0' ) then
              mst_llwr_sm_state <= LLWR_SNGL_INIT;
            elsif ( mst_cmd_sm_start_wr_llink = '1' and mst_cntl_burst = '1' ) then
              mst_llwr_sm_state <= LLWR_BRST_INIT;
            else
              mst_llwr_sm_state <= LLWR_IDLE;
            end if;

          when LLWR_SNGL_INIT =>
            mst_llwr_sm_state   <= LLWR_SNGL;
            mst_llwr_sm_src_rdy <= '1';
            mst_llwr_sm_sof     <= '1';
            mst_llwr_sm_eof     <= '1';

          when LLWR_SNGL =>
            -- destination discontinue write
            if ( Bus2IP_MstWr_dst_dsc_n = '0' and Bus2IP_MstWr_dst_rdy_n = '0' ) then
              mst_llwr_sm_state   <= LLWR_IDLE;
              mst_llwr_sm_src_rdy <= '0';
              mst_llwr_sm_eof     <= '0';
            -- single data beat transfer complete
            elsif ( mst_fifo_valid_read_xfer = '1' ) then
              mst_llwr_sm_state   <= LLWR_IDLE;
              mst_llwr_sm_src_rdy <= '0';
              mst_llwr_sm_sof     <= '0';
              mst_llwr_sm_eof     <= '0';
            -- wait on destination
            else
              mst_llwr_sm_state   <= LLWR_SNGL;
              mst_llwr_sm_src_rdy <= '1';
              mst_llwr_sm_sof     <= '1';
              mst_llwr_sm_eof     <= '1';
            end if;

          when LLWR_BRST_INIT =>
            mst_llwr_sm_state   <= LLWR_BRST;
            mst_llwr_sm_src_rdy <= '1';
            mst_llwr_sm_sof     <= '1';
            mst_llwr_byte_cnt   <= CONV_INTEGER(mst_xfer_length);

          when LLWR_BRST =>
            if ( mst_fifo_valid_read_xfer = '1' ) then
              mst_llwr_sm_sof <= '0';
            else
              mst_llwr_sm_sof <= mst_llwr_sm_sof;
            end if;
            -- destination discontinue write
            if ( Bus2IP_MstWr_dst_dsc_n = '0' and
                 Bus2IP_MstWr_dst_rdy_n = '0' ) then
              mst_llwr_sm_state   <= LLWR_IDLE;
              mst_llwr_sm_src_rdy <= '1';
              mst_llwr_sm_eof     <= '1';
            -- last data beat write
            elsif ( mst_fifo_valid_read_xfer = '1' and
                   (mst_llwr_byte_cnt-BYTES_PER_BEAT) <= BYTES_PER_BEAT ) then
              mst_llwr_sm_state   <= LLWR_BRST_LAST_BEAT;
              mst_llwr_sm_src_rdy <= '1';
              mst_llwr_sm_eof     <= '1';
            -- wait on destination
            else
              mst_llwr_sm_state   <= LLWR_BRST;
              mst_llwr_sm_src_rdy <= '1';
              -- decrement write transfer counter if it's a valid write
              if ( mst_fifo_valid_read_xfer = '1' ) then
                mst_llwr_byte_cnt <= mst_llwr_byte_cnt - BYTES_PER_BEAT;
              else
                mst_llwr_byte_cnt <= mst_llwr_byte_cnt;
              end if;
            end if;

          when LLWR_BRST_LAST_BEAT =>
            -- destination discontinue write
            if ( Bus2IP_MstWr_dst_dsc_n = '0' and
                 Bus2IP_MstWr_dst_rdy_n = '0' ) then
              mst_llwr_sm_state   <= LLWR_IDLE;
              mst_llwr_sm_src_rdy <= '0';
            -- last data beat done
            elsif ( mst_fifo_valid_read_xfer = '1' ) then
              mst_llwr_sm_state   <= LLWR_IDLE;
              mst_llwr_sm_src_rdy <= '0';
            -- wait on destination
            else
              mst_llwr_sm_state   <= LLWR_BRST_LAST_BEAT;
              mst_llwr_sm_src_rdy <= '1';
              mst_llwr_sm_eof     <= '1';
            end if;

          when others =>
            mst_llwr_sm_state <= LLWR_IDLE;

        end case;

      end if;
    else
      null;
    end if;

  end process LLINK_WR_SM_PROC;

  -- local srl fifo for data storage
  mst_fifo_valid_write_xfer <= not(Bus2IP_MstRd_src_rdy_n) and mst_llrd_sm_dst_rdy;
  mst_fifo_valid_read_xfer  <= not(Bus2IP_MstWr_dst_rdy_n) and mst_llwr_sm_src_rdy;

  DATA_CAPTURE_FIFO_I : entity proc_common_v2_00_a.srl_fifo_f
    generic map
    (
      C_DWIDTH   => C_MST_DWIDTH,
      C_DEPTH    => 128
    )
    port map
    (
      Clk        => Bus2IP_Clk,
      Reset      => Bus2IP_Reset,
      FIFO_Write => mst_fifo_valid_write_xfer,
      Data_In    => Bus2IP_MstRd_d,
      FIFO_Read  => mst_fifo_valid_read_xfer,
      Data_Out   => IP2Bus_MstWr_d,
      FIFO_Full  => open,
      FIFO_Empty => open,
      Addr       => open
    );


  ------------------------------------------
  -- Slave access to burst RAM
  ------------------------------------------
  mem_select      <= Bus2IP_CS;
  mem_read_enable <= ( Bus2IP_CS(0) ) and Bus2IP_RdReq;
  mem_read_ack    <= mem_read_ack_dly1;
  mem_write_ack   <= ( Bus2IP_CS(0) ) and Bus2IP_WrReq;
  mem_address     <= Bus2IP_Addr(C_SLV_AWIDTH-11 to C_SLV_AWIDTH-4);

  -- this process generates the read acknowledge 1 clock after read enable
  -- is presented to the BRAM block. The BRAM block has a 1 clock delay
  -- from read enable to data out.
  BRAM_RD_ACK_PROC : process( Bus2IP_Clk ) is
  begin

    if ( Bus2IP_Clk'event and Bus2IP_Clk = '1' ) then
      if ( Bus2IP_Reset = '1' ) then
        mem_read_ack_dly1 <= '0';
      else
        mem_read_ack_dly1 <= mem_read_enable;
      end if;
    end if;

  end process BRAM_RD_ACK_PROC;

  -- connect burst RAM
  assert C_BURST_DWIDTH = C_SLV_DWIDTH;
  
  o_burstAddr <= mem_address;
  o_burstData <= Bus2IP_Data;
  mem_data_out(0) <= i_burstData;
  o_burstWE <= not(Bus2IP_RNW) and
               mem_select(0);
  o_burstBE <= Bus2IP_BE;

  -- implement Block RAM read mux
  MEM_IP2BUS_DATA_PROC : process( mem_data_out, mem_select ) is
  begin

    case mem_select is
      when "1" => mem_ip2bus_data <= mem_data_out(0);
      when others => mem_ip2bus_data <= (others => '0');
    end case;

  end process MEM_IP2BUS_DATA_PROC;


  ------------------------------------------
  -- Example code to drive IP to Bus signals
  ------------------------------------------
  IP2Bus_Data  <= mst_ip2bus_data when mst_read_ack = '1' else
                  mem_ip2bus_data when mem_read_ack = '1' else
                  (others => '0');

  IP2Bus_AddrAck <= mst_write_ack or mst_read_ack or mem_write_ack or mem_read_enable;
  IP2Bus_WrAck <= mst_write_ack or mem_write_ack;
  IP2Bus_RdAck <= mst_read_ack or mem_read_ack;
  IP2Bus_Error <= '0';

end IMP;
