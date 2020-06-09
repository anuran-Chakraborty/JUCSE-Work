----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:44:18 06/07/2020 
-- Design Name: 
-- Module Name:    fourto2enc_beh2 - Behavioral 
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

entity fourto2enc_beh2 is
    Port ( i : in  STD_LOGIC_VECTOR (3 downto 0);
           o : out STD_LOGIC_VECTOR (1 downto 0));
end fourto2enc_beh2;

architecture Behavioral of fourto2enc_beh2 is

begin

Process(i)
begin
	case i is
		when "0001" => o<="00";
		when "0010" => o<="01";
		when "0100" => o<="10";
		when "1000" => o<="11";
		when others => o<="ZZ";
	end case;

end Process;

end Behavioral;

