----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:29:56 02/03/2020 
-- Design Name: 
-- Module Name:    dc - Behavioral 
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

entity dc is
    Port ( e : in  bit;
           i : in  bit;
           o : out  bit_VECTOR (1 downto 0));
end dc;

architecture Behavioral of dc is

begin
process(e,i)
begin
	case (e & i) is 
		when "10" => o<="01";
		when "11" => o<="10";
		when others => o<="00";
	end case;
end process;
end Behavioral;

