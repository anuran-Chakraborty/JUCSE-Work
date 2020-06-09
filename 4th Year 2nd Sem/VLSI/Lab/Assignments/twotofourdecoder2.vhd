----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:09:16 02/03/2020 
-- Design Name: 
-- Module Name:    twotofourdecoder2 - Behavioral 
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
use IEEE.BIT_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity twotofourdecoder2 is
    Port ( e : in  BIT;
           i : in  BIT_VECTOR (1 downto 0);
           o : out  BIT_VECTOR (3 downto 0));
end twotofourdecoder2;

architecture Behavioral of twotofourdecoder2 is

begin

	o(0)<= e and not(i(1)) and not (i(0));
	o(1)<= e and not(i(1)) and (i(0));
	o(2)<= e and(i(1)) and not (i(0));
	o(3)<= e and (i(1)) and (i(0));


end Behavioral;

