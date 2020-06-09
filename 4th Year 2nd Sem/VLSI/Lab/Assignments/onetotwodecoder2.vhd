----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:34:38 02/03/2020 
-- Design Name: 
-- Module Name:    onetotwodecoder2 - Behavioral 
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

entity onetotwodecoder2 is
    Port ( e : in  BIT;
           i : in  BIT;
           o : out  BIT_VECTOR (1 downto 0));
end onetotwodecoder2;

architecture Behavioral of onetotwodecoder2 is

begin
		
	with (e & i) select o<=
		"01" when "10",
		"10" when "11",
		"00" when others;
end Behavioral;

