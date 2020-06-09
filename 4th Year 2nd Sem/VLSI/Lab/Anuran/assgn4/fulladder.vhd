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
    Port ( x : in  BIT;
           y : in  BIT;
           z : in  BIT;
           s : out BIT;
           c : out BIT);
end fulladder;

architecture Behavioral of fulladder is

component halfadder 
    Port ( a : in  BIT;
           b : in  BIT;
           s : out BIT;
           c : out BIT);
end component;

signal ins:BIT;
signal inc:BIT;
signal inc2:BIT;

begin

	h1:halfadder port map(x,y,ins,inc);
	h2:halfadder port map(z,ins,s,inc2);
	c<=inc2 or inc;
	
end Behavioral;

