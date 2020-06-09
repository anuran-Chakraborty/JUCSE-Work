----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:36:27 02/10/2020 
-- Design Name: 
-- Module Name:    fulladder2 - Behavioral 
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

entity fulladder2 is
    Port ( i : in  BIT_VECTOR (2 downto 0);
           sum : out  BIT;
           carry : out  BIT);
end fulladder2;

architecture Behavioral of fulladder2 is

procedure halfadder (signal inp:in BIT_VECTOR(1 downto 0);
						  signal s:out BIT;
						  signal c:out BIT) is
begin
	
	s<=inp(1) xor inp(0);
	c<=inp(1) and inp(0);
end procedure;

signal a,b,d: BIT;
signal in1,in2:BIT_VECTOR(1 downto 0);
begin
	in1<=i(1 downto 0);
	in2<=i(2)& a;
	ha1:halfadder(in1,a,b);
	ha2:halfadder(in2,sum,d);
	carry<=b or d;

end Behavioral;

