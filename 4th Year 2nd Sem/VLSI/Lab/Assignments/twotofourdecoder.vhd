----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:54:00 02/03/2020 
-- Design Name: 
-- Module Name:    twotofourdecoder - Behavioral 
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

entity twotofourdecoder is
    Port ( e : in  BIT;
           i : in  BIT_VECTOR (1 downto 0);
           o : out BIT_VECTOR (3 downto 0));
end twotofourdecoder;

architecture Behavioral of twotofourdecoder is

component onetotwodecoder 
    Port ( e : in  BIT;
           i : in  BIT;
           o : out BIT_VECTOR (1 downto 0));
end component;
signal a:BIT_VECTOR (1 downto 0);

begin

d1:onetotwodecoder port map(e,i(1),a);
d2:onetotwodecoder port map(a(0),i(0),o(1 downto 0));
d3:onetotwodecoder port map(a(1),i(0),o(3 downto 2));



end Behavioral;

