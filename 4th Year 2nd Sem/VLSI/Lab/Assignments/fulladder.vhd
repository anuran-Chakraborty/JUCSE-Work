----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    23:36:06 02/09/2020 
-- Design Name: 
-- Module Name:    fulladder - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity fulladder is
    Port ( x : in  STD_LOGIC;
           y : in  STD_LOGIC;
           z : in  STD_LOGIC;
           s : out STD_LOGIC;
           c : out STD_LOGIC);
end fulladder;

architecture Behavioral of fulladder is

component halfadder 
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           s : out STD_LOGIC;
           c : out STD_LOGIC);
end component;

signal ins:STD_LOGIC;
signal inc:STD_LOGIC;
signal inc2:STD_LOGIC;

begin

	h1:halfadder port map(x,y,ins,inc);
	h2:halfadder port map(z,ins,s,inc2);
	c<=inc2 or inc;
	
end Behavioral;

