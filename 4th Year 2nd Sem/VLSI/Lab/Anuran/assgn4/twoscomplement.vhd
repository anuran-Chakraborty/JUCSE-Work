----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:18:26 02/17/2020 
-- Design Name: 
-- Module Name:    twoscomplement - Behavioral 
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

entity twoscomplement is
    Port ( a : in  BIT_VECTOR (7 downto 0);
           o : out  BIT_VECTOR (7 downto 0));
end twoscomplement;

architecture Behavioral of twoscomplement is


begin
	process(a)
	variable int:BIT_VECTOR (7 downto 0);
	variable f:BIT;
	begin
	--int<=a;
	f:='0';
 	for i in 0 to 7 loop
		
		if(f='1') then
			o(i)<=not(a(i));
		else
			o(i)<=a(i);
		end if;
		if(a(i)='1') then
			f:='1';
		end if;	
	end loop;
	end process;
end Behavioral;

