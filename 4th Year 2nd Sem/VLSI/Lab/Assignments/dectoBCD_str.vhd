----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:21:23 01/27/2020 
-- Design Name: 
-- Module Name:    dectoBCD_str - Behavioral 
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

entity dectoBCD_str is
    Port ( i : in  STD_LOGIC_VECTOR (9 downto 0);
           o : out  STD_LOGIC_VECTOR (3 downto 0));
end dectoBCD_str;

architecture Behavioral of dectoBCD_str is

begin
	o(3) <= i(9) or i(8);
	o(2) <= i(7) or i(6) or i(5) or i(4);
	o(1) <= i(7) or i(6) or i(3) or i(2);
	o(0) <= i(9) or i(7) or i(5) or i(3) or i(1);

end Behavioral;

