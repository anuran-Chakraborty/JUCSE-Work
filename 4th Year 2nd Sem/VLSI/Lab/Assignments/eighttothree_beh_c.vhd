----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:47:07 01/27/2020 
-- Design Name: 
-- Module Name:    eighttothree_beh_c - Behavioral 
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

entity eighttothree_beh_c is
    Port ( i : in  STD_LOGIC_VECTOR (7 downto 0);
           o : out  STD_LOGIC_VECTOR (2 downto 0));
end eighttothree_beh_c;

architecture Behavioral of eighttothree_beh_c is

begin
with i select o<=
	"000" when "00000001",
	"001" when "00000010",
	"010" when "00000100",
	"011" when "00001000",
	
	"100" when "00010000",
	"101" when "00100000",
	"110" when "01000000",
	"111" when "10000000",
	
	"ZZZ" when others ;
	
end Behavioral;

