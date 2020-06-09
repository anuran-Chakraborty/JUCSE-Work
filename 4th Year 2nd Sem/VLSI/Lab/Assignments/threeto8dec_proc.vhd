----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:23:36 06/07/2020 
-- Design Name: 
-- Module Name:    threeto8dec_proc - Behavioral 
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

entity threeto8dec_proc is
    Port ( inp : in  STD_LOGIC_VECTOR (2 downto 0);
           op : out  STD_LOGIC_VECTOR (7 downto 0));
end threeto8dec_proc;

architecture Behavioral of threeto8dec_proc is


procedure twotofourdecoder3 ( e : in  STD_LOGIC;
           i : in  STD_LOGIC_VECTOR (1 downto 0);
           o : out  STD_LOGIC_VECTOR (3 downto 0)) is
begin

	with (e & i) select o:=
		"0001" when "100",
		"0010" when "101",
		"0100" when "110",
		"1000" when "111",
		"0000" when others;
	
end procedure;

begin
		
	process(inp)
	variable varop:STD_LOGIC_VECTOR (7 downto 0);
	begin
		
		dec1:twotofourdecoder3(inp(2),inp(1 downto 0),varop(7 downto 4));
		dec2:twotofourdecoder3(not inp(2),inp(1 downto 0),varop(3 downto 0));
		op<=varop;
	end process;
	

end Behavioral;

