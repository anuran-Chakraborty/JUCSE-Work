----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:09:23 02/17/2020 
-- Design Name: 
-- Module Name:    addersub - Behavioral 
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

entity addersub is
    Port ( a : in  BIT_VECTOR (3 downto 0);
           b : in  BIT_VECTOR (3 downto 0);
           cin : in  BIT;
           s : out  BIT_VECTOR (3 downto 0);
           cout : out  BIT);
end addersub;

architecture Behavioral of addersub is

component fulladder
    Port ( x : in  BIT;
           y : in  BIT;
           z : in  BIT;
           s : out BIT;
           c : out BIT);
end component;

signal c:BIT_VECTOR (4 downto 0);
signal inputb:BIT_VECTOR (3 downto 0);

begin

	inputb<=b when cin='0' else not(b);
	c(0)<=cin;
	gen1:for i in 0 to 3 generate
		fa:fulladder port map(a(i),inputb(i),c(i),s(i),c(i+1));
	end generate;
	
	cout<='0' when cin='1' and c(4)='1' else c(4);

end Behavioral;

