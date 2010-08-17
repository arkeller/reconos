--!
--! \file user_logic.vhd
--!
--! OSIF logic and interface to IPIF
--!
--! The user_logic contains processes for OS request handling. It also
--! instantiates the PLB bus master and bus slave modules, which are respon-
--! sible for initiating bus master transfers and slave requests,
--! respectively. Also, it instantiates the DCR slave module, which
--! manages communication between the CPU and the OSIF.
--!
--! There are two sets of registers, one for each direction (logic to bus
--! and bus to logic). Each set has the a register for command, data, 
--! (both DCR) and shared memory (PLB, if configured); the bus to logic 
--! set has another handshake register indicating an incoming request 
--! from the DCR bus.
--!
--! Communication with the user task goes through the osif_task2os and
--! osif_os2task data structures, which are converted to std_logic_vectors
--! at the module interface, because XPS cannot handle VHDL records. An
--! incoming request from a task to perform an operating system call
--! is signalled by the request line of the task2os record. Requests can be
--! divided into two categories: 
--!
--!    - those that are handled in hardware without microprocessor 
--!      involvement (like shared memory accesses), and
--!    - those that have to be handled in the microprocessor
--!
--! The first are handled directly within user_logic (and its submodules),
--! whereas the latter cause an interrupt to the microprocessor, preempt
--! any running processes there and wake up a software thread, which then
--! acts on behalf of the hardware thread.
--!
--!
--!
--!                                                     FIFO >--+    +  --> FIFO
--!                                                          ___|____|_____
--!                    Memory bus interface                 |              |
--!   Memory              (master/slave)                    |   fifo_mgr   |
--!    Bus     <----------------------------+               |______________|
--! (e.g. PLB)                              |                     |
--!                                         |    +----------------+
--!                                  _______|____|____ 
--!                                 |                 |
--!   clk, reset ------------------>| command_decoder |
--!                                 |_________________|
--!                                         |    |
--!                                         |    +----------------+
--!  Hardware                               |                _____|__________
--!   Thread  <-----------------------------+               |                |
--!             Hardware Thread Control Interface           | dcr_slave_regs |
--!                                                         |________________|
--!                                                                ^
--!                                                                |
--!                                                                V
--!                                                              D C R
--! \author     Enno Luebbers   <enno.luebbers@upb.de>
--! \date       08.12.2008
--
-----------------------------------------------------------------------------
-- %%%RECONOS_COPYRIGHT_BEGIN%%%
-- 
-- This file is part of the ReconOS project <http://www.reconos.de>.
-- Copyright (c) 2008, Computer Engineering Group, University of
-- Paderborn. 
-- 
-- For details regarding licensing and redistribution, see COPYING.  If
-- you did not receive a COPYING file as part of the distribution package
-- containing this file, you can get it at http://www.reconos.de/COPYING.
-- 
-- This software is provided "as is" without express or implied warranty,
-- and with no claim as to its suitability for any particular purpose.
-- The copyright owner or the contributors shall not be liable for any
-- damages arising out of the use of this software.
-- 
-- %%%RECONOS_COPYRIGHT_END%%%
-----------------------------------------------------------------------------
--
-- Major changes
-- 01.08.2006  Enno Luebbers     File created (from opb_reconos_slot_v1_00_c)
-- 03.08.2006  Enno Luebbers     Added PLB bus master (moved to v1.01.a),
--                               removed BRAM interface
-- 04.08.2006  Enno Luebbers     moved user_logic to toplevel
-- 07.08.2006  Enno Luebbers     moved logic to separate modules
--                               (bus_master, bus_slave_regs)
-- xx.10.2007  Enno Luebbers     added local FIFO manager
-- 23.11.2007  Enno Luebbers     moved slave registers to DCR
-- 08.12.2008  Enno Luebbers     modularized (moved memory bus controller
--                               to separate module)
--
--*************************************************************************/
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

--library proc_common_v1_00_b;
--use proc_common_v1_00_b.proc_common_pkg.all;

library reconos_v2_01_a;
use reconos_v2_01_a.reconos_pkg.all;

library osif_v2_01_a;
use osif_v2_01_a.all;

entity user_logic is
    generic
        (
            C_BASEADDR            :     std_logic_vector := X"FFFFFFFF";
            -- Bus protocol parameters
            C_AWIDTH              :     integer          := 32;
            C_DWIDTH              :     integer          := 32;
            C_PLB_AWIDTH          :     integer          := 32;
            C_PLB_DWIDTH          :     integer          := 64;
            C_NUM_CE              :     integer          := 2;
            C_BURST_AWIDTH        :     integer          := 13;  -- 1024 x 64 Bit = 8192 Bytes = 2^13 Bytes
            C_BURST_BASEADDR      :     std_logic_vector := X"00004000";  -- system memory base address for burst ram access
            C_THREAD_RESET_CYCLES :     natural          := 10;  -- number of cycles the thread reset is held
            C_FIFO_DWIDTH         :     integer          := 32;
            C_DCR_BASEADDR        :     std_logic_vector := "1111111111";
            C_DCR_HIGHADDR        :     std_logic_vector := "0000000000";
            C_DCR_AWIDTH          :     integer          := 10;
            C_DCR_DWIDTH          :     integer          := 32;
            C_DCR_ILA             :     integer          := 0  -- 0: no debug ILA, 1: include debug chipscope ILA for DCR debugging
            );
    port
        (
            sys_clk               : in  std_logic;
            sys_reset             : in  std_logic;
            interrupt             : out std_logic;
            busy                  : out std_logic;
            blocking              : out std_logic;
            -- task interface
            task_clk              : out std_logic;
            task_reset            : out std_logic;
            osif_os2task_vec      : out std_logic_vector(0 to C_OSIF_OS2TASK_REC_WIDTH-1);
            osif_task2os_vec      : in  std_logic_vector(0 to C_OSIF_TASK2OS_REC_WIDTH-1);

            -- FIFO access signals
            -- left (read) FIFO
            o_fifo_read_en     : out std_logic;
            i_fifo_read_data   : in  std_logic_vector(0 to C_FIFO_DWIDTH-1);
            i_fifo_read_ready  : in  std_logic;
            -- right (write) FIFO
            o_fifo_write_en    : out std_logic;
            o_fifo_write_data  : out std_logic_vector(0 to C_FIFO_DWIDTH-1);
            i_fifo_write_ready : in  std_logic;

            -- memory access signals
            o_mem_singleData  : out std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
            i_mem_singleData  : in  std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
            o_mem_localAddr   : out std_logic_vector(0 to C_AWIDTH-1);
            o_mem_targetAddr  : out std_logic_vector(0 to C_AWIDTH-1);
            o_mem_singleRdReq : out std_logic;
            o_mem_singleWrReq : out std_logic;
            o_mem_burstRdReq  : out std_logic;
            o_mem_burstWrReq  : out std_logic;
            o_mem_burstLen    : out std_logic_vector(0 to 4);

            i_mem_busy   : in std_logic;
            i_mem_rdDone : in std_logic;
            i_mem_wrDone : in std_logic;


            -- bus macro control
            o_bm_enable : out std_logic;

            -- dcr bus protocol ports
            o_dcrAck   : out std_logic;
            o_dcrDBus  : out std_logic_vector(0 to C_DCR_DWIDTH-1);
            i_dcrABus  : in  std_logic_vector(0 to C_DCR_AWIDTH-1);
            i_dcrDBus  : in  std_logic_vector(0 to C_DCR_DWIDTH-1);
            i_dcrRead  : in  std_logic;
            i_dcrWrite : in  std_logic;
            i_dcrICON  : in  std_logic_vector(35 downto 0)

            );
end entity user_logic;

------------------------------------------------------------------------------
-- Architecture section
------------------------------------------------------------------------------

architecture IMP of user_logic is


--#################################################################################################################


    -------
    -- OS signals
    -------
    -- between os and task
    signal osif_os2task : osif_os2task_t;
    signal osif_task2os : osif_task2os_t;

    -- FIXME: is there a better way than a handshake register?
    signal os2task_newcmd     : std_logic := '0';
    signal request_blocking   : std_logic := '0';
    signal request_unblocking : std_logic := '0';
-- signal os2task_reset : std_logic := '0';
    signal task2os_error      : std_logic := '0';  -- FIXME: this is being ignored

    -- dirty flag signals indicating unread data in read registers
    signal slv_busy        : std_logic;
    signal post_sw_request : std_logic;

    ---------
    -- slave register signals (put on DCR)
    ---------
    signal slv_bus2osif_command : std_logic_vector(0 to C_OSIF_CMD_WIDTH-1);
    signal slv_bus2osif_data    : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
    signal slv_bus2osif_done    : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
    signal slv_osif2bus_command : std_logic_vector(0 to C_OSIF_CMD_WIDTH-1)  := (others => '0');  -- task2os command
    signal slv_osif2bus_data    : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1) := (others => '0');  -- task2os data
    signal slv_osif2bus_datax   : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1) := (others => '0');  -- task2os data

    ---------
    -- status registers
    ---------
    signal thread_init_data : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);  -- thread data (passed at initialization)


    ---------
    -- local FIFO control and data lines
    ---------
    signal fifomgr_read_remove : std_logic;
    signal fifomgr_read_data   : std_logic_vector(0 to C_FIFO_DWIDTH-1);
    signal fifomgr_read_wait   : std_logic;
    signal fifomgr_write_add   : std_logic;
    signal fifomgr_write_data  : std_logic_vector(0 to C_FIFO_DWIDTH-1);
    signal fifomgr_write_wait  : std_logic;

    ---------
    -- local FIFO handles (used for FIFO message routing)
    ---------
    signal fifo_read_handle  : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);
    signal fifo_write_handle : std_logic_vector(0 to C_OSIF_DATA_WIDTH-1);

    ---------
    -- thread reset counter
    ---------
    signal reset_counter  : natural range 0 to C_THREAD_RESET_CYCLES-1 := C_THREAD_RESET_CYCLES-1;
    signal request_reset  : std_logic;
    signal thread_reset_i : std_logic;

begin

    -- ################### MODULE INSTANTIATIONS ####################


    -----------------------------------------------------------------------
    -- dcr_slave_regs_inst: DCR bus slave instatiation
    --
    -- Handles access to the various registers.
    -- NOTE: While slv_bus2osif_* signals are latched by bus_slave_regs,
    --       the slv_osif2bus_* signals MUST BE STABLE until the transaction
    --       is complete (busy goes low for s/w OS requests or the shm bus
    --       bus master transaction completes).
    -----------------------------------------------------------------------
    dcr_slave_regs_inst : entity osif_v2_01_a.dcr_slave_regs
        generic map (
            C_DCR_BASEADDR       => C_DCR_BASEADDR,
            C_DCR_HIGHADDR       => C_DCR_HIGHADDR,
            C_DCR_AWIDTH         => C_DCR_AWIDTH,
            C_DCR_DWIDTH         => C_DCR_DWIDTH,
            C_NUM_REGS           => 4,
            C_INCLUDE_ILA        => C_DCR_ILA
            )
        port map (
            clk                  => sys_clk,
            reset                => thread_reset_i,  --sys_reset,
            o_dcrAck             => o_dcrAck,
            o_dcrDBus            => o_dcrDBus,
            i_dcrABus            => i_dcrABus,
            i_dcrDBus            => i_dcrDBus,
            i_dcrRead            => i_dcrRead,
            i_dcrWrite           => i_dcrWrite,
            i_dcrICON            => i_dcrICON,
            -- user registers
            slv_osif2bus_command => slv_osif2bus_command,
            slv_osif2bus_data    => slv_osif2bus_data,
            slv_osif2bus_datax   => slv_osif2bus_datax,
            slv_bus2osif_command => slv_bus2osif_command,
            slv_bus2osif_data    => slv_bus2osif_data,
            slv_bus2osif_done    => slv_bus2osif_done,
            -- additional user interface
            o_newcmd             => os2task_newcmd,
            i_post               => post_sw_request,
            o_busy               => slv_busy,
            o_interrupt          => interrupt
            );

    -----------------------------------------------------------------------
    -- command_decoder_inst: command decoder instatiation
    --
    -- Handles decoding the commands from the HW thread.
    -- NOTE: the command decoder is completely asynchronous. It also
    --       handles the setting and releasing of the osif_os2task.busy
    --       and .blocking signals.
    -----------------------------------------------------------------------
    command_decoder_inst : entity osif_v2_01_a.command_decoder
        generic map (
            C_BASEADDR             => C_BASEADDR,
            C_AWIDTH               => C_AWIDTH,
            C_DWIDTH               => C_DWIDTH,
            C_PLB_AWIDTH           => C_PLB_AWIDTH,
            C_PLB_DWIDTH           => C_PLB_DWIDTH,
            C_BURST_AWIDTH         => C_BURST_AWIDTH,
            C_BURST_BASEADDR       => C_BURST_BASEADDR,
            C_FIFO_DWIDTH          => C_FIFO_DWIDTH)
        port map (
            i_clk                  => sys_clk,
            i_reset                => thread_reset_i,  -- Bus2IP_Reset,
            i_osif                 => osif_task2os,
            o_osif                 => osif_os2task,
            o_sw_request           => post_sw_request,
            i_request_blocking     => request_blocking,
            i_release_blocking     => request_unblocking,
            i_init_data            => thread_init_data,
            o_bm_my_addr           => o_mem_localAddr,
            o_bm_target_addr       => o_mem_targetAddr,
            o_bm_read_req          => o_mem_singleRdReq,
            o_bm_write_req         => o_mem_singleWrReq,
            o_bm_burst_read_req    => o_mem_burstRdReq,
            o_bm_burst_write_req   => o_mem_burstWrReq,
            o_bm_burst_length      => o_mem_burstLen,
            i_bm_busy              => i_mem_busy,
            i_bm_read_done         => i_mem_rdDone,
            i_bm_write_done        => i_mem_wrDone,
            i_slv_busy             => slv_busy,
            i_slv_bus2osif_command => slv_bus2osif_command,
            i_slv_bus2osif_data    => slv_bus2osif_data,
            i_slv_bus2osif_shm     => i_mem_singleData,
            o_slv_osif2bus_command => slv_osif2bus_command,
            o_slv_osif2bus_data    => slv_osif2bus_data,
            o_slv_osif2bus_datax   => slv_osif2bus_datax,
            o_slv_osif2bus_shm     => o_mem_singleData,
            o_fifo_read_remove     => fifomgr_read_remove,
            i_fifo_read_data       => fifomgr_read_data,
            i_fifo_read_wait       => fifomgr_read_wait,
            o_fifo_write_add       => fifomgr_write_add,
            o_fifo_write_data      => fifomgr_write_data,
            i_fifo_write_wait      => fifomgr_write_wait,
            i_fifo_read_handle     => fifo_read_handle,
            i_fifo_write_handle    => fifo_write_handle );


    -----------------------------------------------------------------------
    -- fifo_mgr_inst: FIFO manager instantiation
    --
    -- The FIFO manager handles incoming push/pop requests to the two
    -- hardware FIFOs attached to the OSIF. It arbitrates between
    -- local hardware-thread-initiated requests and indirect bus accesses
    -- by other hardware threads.
    -----------------------------------------------------------------------

    fifo_mgr_inst : entity osif_v2_01_a.fifo_mgr
        generic map (
            C_FIFO_DWIDTH       => C_FIFO_DWIDTH
            )
        port map (
            clk                 => sys_clk,
            reset               => sys_reset,  -- we don't want a thread reset command to flush
                                        -- the FIFOs, therefore no thread_reset_i!
            -- local FIFO access signals
            i_local_read_remove => fifomgr_read_remove,
            o_local_read_data   => fifomgr_read_data,
            o_local_read_wait   => fifomgr_read_wait,
            i_local_write_add   => fifomgr_write_add,
            i_local_write_data  => fifomgr_write_data,
            o_local_write_wait  => fifomgr_write_wait,
            -- "real" FIFO access signals
            o_fifo_read_en      => o_fifo_read_en,
            i_fifo_read_data    => i_fifo_read_data,
            i_fifo_read_ready   => i_fifo_read_ready,
            o_fifo_write_en     => o_fifo_write_en,
            o_fifo_write_data   => o_fifo_write_data,
            i_fifo_write_ready  => i_fifo_write_ready
            -- TODO: signal to communicate with the bus_slave_regs module
            );



    -- ################### CONCURRENT ASSIGNMENTS ####################

    -----------------------------------------------------------------------
    -- User task signal routing
    --
    -- The user task is supplied with a dedicated clock and reset signal,
    -- just in case we want to use them later.
    -----------------------------------------------------------------------
    task_clk       <= sys_clk;          --Bus2IP_Clk;
    thread_reset_i <= '1' when reset_counter > 0 else '0';
    task_reset     <= thread_reset_i;

    -- OSIF record to vector conversion (because EDK cannot handle records)
    osif_os2task_vec <= to_std_logic_vector(osif_os2task);
    osif_task2os     <= to_osif_task2os_t(osif_task2os_vec);

    -- FIXME: ignoring task error
    task2os_error <= osif_task2os.error;


    -- drive debug signals
    busy     <= osif_os2task.busy;
    blocking <= osif_os2task.blocking;



    -- ################### PROCESSES ####################

    -----------------------------------------------------------------------
    -- handle_os2task_response: Handles incoming OS commands
    --
    -- Especially the OSIF_CMD_UNBLOCK command, which signals that a
    -- blocking OS call has returned.
    -----------------------------------------------------------------------
    -- FIXME: does this have to be synchronous?
    handle_os2task_response : process(sys_clk, sys_reset)
    begin
        if sys_reset = '1' then
            request_blocking   <= '0';
            request_unblocking <= '0';
            request_reset      <= '0';
            o_bm_enable        <= '0';  -- bus macros are disabled by default!
            thread_init_data   <= (others => '0');
        elsif rising_edge(sys_clk) then

            request_blocking   <= '0';
            request_unblocking <= '0';
            request_reset      <= '0';

            if os2task_newcmd = '1' then
                case slv_bus2osif_command(0 to C_OSIF_CMD_WIDTH-1) is
                    when OSIF_CMD_UNBLOCK =>
                        request_unblocking <= '1';

                    when OSIF_CMD_SET_INIT_DATA =>
                        thread_init_data     <= slv_bus2osif_data;
                        
                    when OSIF_CMD_RESET =>
                        request_blocking <= '1';
                        request_reset <= '1';
                        
                    when OSIF_CMD_BUSMACRO =>
                        if slv_bus2osif_data = OSIF_DATA_BUSMACRO_DISABLE then -- disable
                            o_bm_enable <= '0';
                        else
                            o_bm_enable <= '1';  -- enable
                        end if;
                        
                    when OSIF_CMD_SET_FIFO_READ_HANDLE =>
                        fifo_read_handle <= slv_bus2osif_data;

                    when OSIF_CMD_SET_FIFO_WRITE_HANDLE =>
                        fifo_write_handle <= slv_bus2osif_data;

                    when others =>

                end case;
            end if;
        end if;
    end process;


    -----------------------------------------------------------------------
    -- reset_proc: handles reset of software thread
    -----------------------------------------------------------------------
    reset_proc: process(sys_clk, sys_reset)
    begin
        if sys_reset = '1' then
            reset_counter <= C_THREAD_RESET_CYCLES-1;
        elsif rising_edge(sys_clk) then
            if request_reset = '1' then
                reset_counter <= C_THREAD_RESET_CYCLES-1;
            elsif reset_counter > 0 then
                reset_counter <= reset_counter - 1;
            end if;
        end if;
    end process;




end IMP;
