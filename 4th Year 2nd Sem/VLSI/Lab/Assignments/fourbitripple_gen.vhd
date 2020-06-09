----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:16:24 06/07/2020 
-- Design Name: 
-- Module Name:    fourbitripple_gen - Behavioral 
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

entity fourbitripple_gen is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           cin : in  STD_LOGIC;
           s : out  STD_LOGIC_VECTOR (3 downto 0);
           cout : out  STD_LOGIC);
end fourbitripple_gen;

architecture Behavioral of fourbitripple_gen is

component fulladder
    Port ( x : in  STD_LOGIC;
           y : in  STD_LOGIC;
           z : in  STD_LOGIC;
           s : out STD_LOGIC;
           c : out STD_LOGIC);
end component;

signal c:STD_LOGIC_VECTOR (4 downto 0);

begin

	c(0)<='0';
	
	gen1: for i in 0 to 3 generate
		fa:fulladder port map(a(i),b(i),c(i),s(i),c(i+1));
	end generate;
	cout<=c(4);


end Behavioral;

