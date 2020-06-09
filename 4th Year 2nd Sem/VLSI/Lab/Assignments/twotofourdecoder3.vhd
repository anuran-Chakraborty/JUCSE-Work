----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:43:50 02/03/2020 
-- Design Name: 
-- Module Name:    twotofourdecoder3 - Behavioral 
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

entity twotofourdecoder3 is
    Port ( e : in  STD_LOGIC;
           i : in  STD_LOGIC_VECTOR (1 downto 0);
           o : out  STD_LOGIC_VECTOR (3 downto 0));
end twotofourdecoder3;

architecture Behavioral of twotofourdecoder3 is

begin

with (e & i) select o<=
	"0001" when "100",
	"0010" when "101",
	"0100" when "110",
	"1000" when "111",
	"0000" when others;
	
end Behavioral;

