------------------------------------------------------------------------------
-- fifo_core.vhd - entity/architecture pair
--
-- original implementation by Jason Agron <jagron@ittc.ku.edu>
-- adapted for ReconOS by Enno Luebbers <luebbers@reconos.de>
------------------------------------------------------------------------------
-- IMPORTANT:
-- DO NOT MODIFY THIS FILE EXCEPT IN THE DESIGNATED SECTIONS.
--
-- SEARCH FOR --USER TO DETERMINE WHERE CHANGES ARE ALLOWED.
--
-- TYPICALLY, THE ONLY ACCEPTABLE CHANGES INVOLVE ADDING NEW
-- PORTS AND GENERICS THAT GET PASSED THROUGH TO THE INSTANTIATION
-- OF THE USER_LOGIC ENTITY.
------------------------------------------------------------------------------
--
-- ***************************************************************************
-- ** Copyright (c) 1995-2007 Xilinx, Inc.  All rights reserved.            **
-- **                                                                       **
-- ** Xilinx, Inc.                                                          **
-- ** XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"         **
-- ** AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND       **
-- ** SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,        **
-- ** OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,        **
-- ** APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION           **
-- ** THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,     **
-- ** AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE      **
-- ** FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY              **
-- ** WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE               **
-- ** IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR        **
-- ** REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF       **
-- ** INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS       **
-- ** FOR A PARTICULAR PURPOSE.                                             **
-- **                                                                       **
-- ***************************************************************************
--
------------------------------------------------------------------------------
-- Filename:          fifo_core.vhd
-- Version:           1.00.a
-- Description:       Top level design, instantiates IPIF and user logic.
-- Date:              Tue Oct  2 15:26:20 2007 (by Create and Import Peripheral Wizard)
-- VHDL Standard:     VHDL'93
------------------------------------------------------------------------------
-- Naming Conventions:
--   active low signals:                    "*_n"
--   clock signals:                         "clk", "clk_div#", "clk_#x"
--   reset signals:                         "rst", "rst_n"
--   generics:                              "C_*"
--   user defined types:                    "*_TYPE"
--   state machine next state:              "*_ns"
--   state machine current state:           "*_cs"
--   combinatorial signals:                 "*_com"
--   pipelined or register delay signals:   "*_d#"
--   counter signals:                       "*cnt*"
--   clock enable signals:                  "*_ce"
--   internal version of output port:       "*_i"
--   device pins:                           "*_pin"
--   ports:                                 "- Names begin with Uppercase"
--   processes:                             "*_PROCESS"
--   component instantiations:              "<ENTITY_>I_<#|FUNC>"
------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

--library proc_common_v2_00_a;
--use proc_common_v2_00_a.proc_common_pkg.all;
--use proc_common_v2_00_a.ipif_pkg.all;
--library opb_ipif_v3_01_c;
--use opb_ipif_v3_01_c.all;

library mbox_fifo_v1_01_a;
use mbox_fifo_v1_01_a.all;

entity mbox_fifo is
  generic (
	ADDRESS_WIDTH	: integer := 9;
	DATA_WIDTH	: integer := 32
	);
  port (
	readClk		: in std_logic;
	readRst		: in std_logic;
	writeClk		: in std_logic;
	writeRst		: in std_logic;
	write		: in std_logic;
	read		: in std_logic;
	dataIn		: in std_logic_vector(0 to DATA_WIDTH-1);
	dataOut		: out std_logic_vector(0 to DATA_WIDTH-1);
	clearToWrite	: out std_logic;
	clearToRead	: out std_logic	
	);

  attribute SIGIS : string;
  attribute SIGIS of readClk       : signal is "Clk";
  attribute SIGIS of writeClk       : signal is "Clk";
  attribute SIGIS of readRst       : signal is "Rst";
  attribute SIGIS of writeRst       : signal is "Rst";
end entity mbox_fifo;

------------------------------------------------------------------------------
-- Architecture section
------------------------------------------------------------------------------

architecture IMP of mbox_fifo is

	-- Component Declaration for the "guts" of the fifo core
component fifo_async

	port (
        din: IN std_logic_VECTOR(31 downto 0);
        rd_clk: IN std_logic;
        rd_en: IN std_logic;
        rst: IN std_logic;
        wr_clk: IN std_logic;
        wr_en: IN std_logic;
        dout: OUT std_logic_VECTOR(31 downto 0);
        empty: OUT std_logic;
        full: OUT std_logic;
        valid: OUT std_logic
	);

end component;

	signal empty : std_logic;
	signal full : std_logic;
	signal valid : std_logic;
	signal reset : std_logic;

begin


  -- instantiate FIFOs
  fifo_inst : fifo_async
                port map (
                        rd_clk => readClk,
                        wr_clk => writeClk,
                        din => dataIn,
                        rd_en => read,
                        rst => reset,
                        wr_en => write,
                        dout => dataOut,
                        empty => empty,
                        full => full,
			               valid => valid);

  reset <= readRst or writeRst;
	clearToRead <= (not empty) or valid;
	clearToWrite <= not full;


end IMP;
