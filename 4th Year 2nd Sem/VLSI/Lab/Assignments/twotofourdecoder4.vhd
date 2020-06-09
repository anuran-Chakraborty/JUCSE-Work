----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:48:03 02/03/2020 
-- Design Name: 
-- Module Name:    twotofourdecoder4 - Behavioral 
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

entity twotofourdecoder4 is
    Port ( e : in  STD_LOGIC;
           i : in  STD_LOGIC_VECTOR (1 downto 0);
           o : out  STD_LOGIC_VECTOR (3 downto 0));
end twotofourdecoder4;

architecture Behavioral of twotofourdecoder4 is

begin

process(e,i)
begin
	
	if(e='0') then
		o<="0000";
	elsif(i="00") then
		o<="0001";
	elsif(i="01") then
		o<="0010";
	elsif(i="10") then
		o<="0100";
	elsif(i="11") then
		o<="1000";
	end if;
end process;
end Behavioral;

