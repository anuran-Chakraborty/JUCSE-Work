----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:10:22 06/07/2020 
-- Design Name: 
-- Module Name:    threeto8dec_comp - Behavioral 
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

entity threeto8dec_comp is
    Port ( inp : in  STD_LOGIC_VECTOR (2 downto 0);
			  en : in  STD_LOGIC;
           op : out  STD_LOGIC_VECTOR (7 downto 0));
end threeto8dec_comp;

architecture Behavioral of threeto8dec_comp is

component twotofourdecoder4 is
    Port ( e : in  STD_LOGIC;
           i : in  STD_LOGIC_VECTOR (1 downto 0);
           o : out  STD_LOGIC_VECTOR (3 downto 0));
end component;
signal notinp:STD_LOGIC;

begin
	notinp<=not inp(2);
	dec1:twotofourdecoder4 port map(inp(2),inp(1 downto 0),op(7 downto 4));
	dec2:twotofourdecoder4 port map(notinp,inp(1 downto 0),op(3 downto 0));
	
end Behavioral;

