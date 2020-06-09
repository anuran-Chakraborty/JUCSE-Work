----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:13:10 02/10/2020 
-- Design Name: 
-- Module Name:    fourbitripplecarry - Behavioral 
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

entity fourbitripplecarry is
    Port ( i1 : in  BIT_VECTOR (3 downto 0);
           i2 : in  BIT_VECTOR (3 downto 0);
			  inpcarry : in  BIT;
           sum : out  BIT_VECTOR (3 downto 0);
           carry : out  BIT);
end fourbitripplecarry;

architecture Behavioral of fourbitripplecarry is

--procedure halfadder (signal inp:in BIT_VECTOR(1 downto 0);
--						  signal s:out BIT;
--						  signal c:out BIT) is
--begin
--	
--	s<=inp(1) xor inp(0);
--	c<=inp(1) and inp(0);
--end procedure;

--signal a,b,d: BIT;
--signal in1,in2:BIT_VECTOR(1 downto 0);
	
procedure fulladder (signal inp:in BIT_VECTOR(2 downto 0);
						  signal s:out BIT;
						  signal c:out BIT) is
						  
begin
	s<=inp(0) xor inp(1) xor inp(2);
	c<=(inp(0) and inp(1)) or (inp(1) and inp(2)) or (inp(2) and inp(0));
--	in1<=inp(1 downto 0);
--	in2<=inp(2)& a;
--	ha1:halfadder(in1,a,b);
--	ha2:halfadder(in2,sum,d);
--	c<=b or d;
	
end procedure;

signal c1,c2,c3,c4: BIT;
signal input: BIT_VECTOR(2 downto 0);
begin
	input<=i1(0) & i2(0) & inpcarry;
	fa1:fulladder(input,sum(0),c1);
	input<=i1(1) & i2(1) & c1;
	fa2:fulladder(input,sum(1),c2);
	input<=i1(2) & i2(2) & c2;
	fa3:fulladder(input,sum(2),c3);
	input<=i1(3) & i2(3) & c3;
	fa4:fulladder(input,sum(3),carry);

end Behavioral;

