----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:08:37 03/02/2020 
-- Design Name: 
-- Module Name:    addersubproc - Behavioral 
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

entity addersubproc is
    Port ( a : in  BIT_VECTOR (3 downto 0);
           b : in  BIT_VECTOR (3 downto 0);
           cin : in  BIT;
           sum : out  BIT_VECTOR (3 downto 0);
           cin : out  BIT);
end addersubproc;

architecture Behavioral of addersubproc is

procedure halfadder(ha,hb:in bit;
							hs,hc:out bit) is
begin
	hs:= ha xor hb;
	hc:= ha and hb;
end procedure;

procedure fulladder(fa,fb,fc:in bit;
							fss,fcc:out bit) is
variable ints1,ints2,intc1,intc2:bit; 
begin
	h1:halfadder(fb,fc,ints1,intc1);
	h2:halfadder(fa,ints1,ints2,intc2);
	fss:=ints2;
	fcc:=intc1 or intc2;
end procedure;

procedure ripplecarry(ra,rb:in bit_vector(3 downto 0),
							 rcin:in bit;
							 rsum:out bit_vector(3 downto 0),
							 rcout:out bit) is
variable c:bit_vector(4 downto 0);
variable ss:bit_vector(3 downto 0);
begin

	c(0):=cin;
		
	for i in 0 to 3 loop
		f:fulladder(a(i),b(i),c(i),ss(i),c(i+1));
	end loop;
	rsum<=ss;
	rcout<=c(4);
end procedure;

begin
	
	process(a,b,cin)
	
	begin
		if(cin='1')
		
	end procedure;

end Behavioral;

