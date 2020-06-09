----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:06:54 06/07/2020 
-- Design Name: 
-- Module Name:    BCDAdder - Behavioral 
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

entity BCDAdder is
    Port ( an : in  STD_LOGIC_VECTOR (3 downto 0);
           bn : in  STD_LOGIC_VECTOR (3 downto 0);
           sum : out  STD_LOGIC_VECTOR (3 downto 0);
           k : inout  STD_LOGIC);
end BCDAdder;

architecture Behavioral of BCDAdder is

component fourbitripple_gen is
    Port ( a : in  STD_LOGIC_VECTOR (3 downto 0);
           b : in  STD_LOGIC_VECTOR (3 downto 0);
           cin : in  STD_LOGIC;
           s : out  STD_LOGIC_VECTOR (3 downto 0);
           cout : out  STD_LOGIC);
end component;

signal binarySum: STD_LOGIC_VECTOR (3 downto 0);
signal carry: STD_LOGIC;
signal condition: STD_LOGIC;
signal toAdd: STD_LOGIC_VECTOR (3 downto 0);
signal nouse: STD_LOGIC;
begin

	rc1:fourbitripple_gen port map(an,bn,'0',binarySum,carry);
	condition<= carry or (binarySum(3) and binarySum(2)) or (binarySum(3) and binarySum(1));
	
	Process(toAdd,condition)
	begin
	
		if(condition='0') then
			toAdd<="0000";
		elsif(condition='1') then
			toAdd<="0110";
		end if;
	end process;
	
	rc2:fourbitripple_gen port map(binarySum,toAdd,'0',sum,k);
end Behavioral;

