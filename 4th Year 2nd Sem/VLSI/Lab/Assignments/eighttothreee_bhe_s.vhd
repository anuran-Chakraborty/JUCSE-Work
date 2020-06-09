----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:55:27 01/27/2020 
-- Design Name: 
-- Module Name:    eighttothreee_bhe_s - Behavioral 
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

entity eighttothreee_bhe_s is
    Port ( i : in  STD_LOGIC_VECTOR (7 downto 0);
           o : out  STD_LOGIC_VECTOR (2 downto 0));
end eighttothreee_bhe_s;

architecture Behavioral of eighttothreee_bhe_s is

begin

Process(i)
begin
	case i is
		when "00000001" => o<="000";
		when "00000010" => o<="001";
		when "00000100" => o<="010";
		when "00001000" => o<="011";
		
		when "00010000" => o<="100";
		when "00100000" => o<="101";
		when "01000000" => o<="110";
		when "10000000" => o<="111";
		
		when others => o<="ZZZ";
	end case;
end Process;

end Behavioral;

