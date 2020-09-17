----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:17:31 06/21/2020 
-- Design Name: 
-- Module Name:    vivaa3 - Behavioral 
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

entity ifelse is
 Port ( a : in STD_LOGIC;
 b : inout STD_LOGIC;
 c : out STD_LOGIC); 
end ifelse;
architecture Behavioral of ifelse is
begin
process(a,b)
begin
 if a=b then
 c<=not(a xor b);
 elsif a>b then
 b<=a;
 c<=b;
 elsif a=b then
 c<=b;
 elsif a<b then
 c<=not(a) and not(b);
 end if;
end process;
end Behavioral;
