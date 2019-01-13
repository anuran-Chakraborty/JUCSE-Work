;Write and test a program to identify the GCD and LCM of three numbers
include mtab.asm
.model small
.stack 100h

.data
	iprompt1 db 10,13,"Enter 3 numbers: $"
	oprompt1 db 10,13,"GCD is: $"
	oprompt2 db 10,13,"LCM is: $"

	num1 dw ?
	num2 dw ?
	num3 dw ?

	gcdn dw ?
	lcmn dw ?

.code
	
	;procedure to find gcd of two numbers
	gcd proc
	; input: bx,ax
	; output: gcd

	; Assumption: cx is greater than bx
	  up: 
	  	  cmp ax,bx        ;compare the two numbers.
		  je exit          ;if equal, go to exit label.
		  jb excg          ;if first number is below than second,
					   ;go to excg label.
	  up1: 
	  	   mov dx,0h       ;initialize the dx.
		   div bx          ;divide the first number by second number.
		   cmp dx,0        ;compare remainder is zero or not.
		   je exit         ;if zero, jump to exit label.
		   mov ax,dx       ;if non-zero, move remainder to ax.
		   jmp up
		             		;jump to up label.
	  excg:
	  	   xchg ax,bx     ;exchange the remainder and quotient.
		   jmp up1        ;jump to up1.
	  exit:
	  	   mov gcdn,bx     ;store the result in gcd.
		   ret
	gcd endp

	lcm proc
	; input: bx,ax
	; output: dx
		xor dx,dx
		mul bx	;product of numbers
		div gcdn	;by gcd of numbers
		mov lcmn,ax
		ret
	lcm endp

	main proc
		
		mov ax,@data
		mov ds,ax

		;input
		printm iprompt1
		; first number
		dec_input
		mov num1,bx

		;second
		dec_input
		mov num2,bx

		;third
		dec_input
		mov num3,bx			

		; ********************** GCD ************************************
		;find GCD of first two
		mov ax,num1
		mov bx,num2
		call gcd

		; GCD of GCD and third 
		mov ax,num3
		mov bx,gcdn
		call gcd

		;output
		printm oprompt1
		mov bx,gcdn
		dec_output
		; ********************** GCD ************************************

		; ********************** LCM ************************************
		; find gcd of two
		mov ax,num1
		mov bx,num2
		call gcd
		; find lcm
		mov ax,num1
		mov bx,num2
		call lcm

		; find gcd of two
		mov ax,lcmn
		mov bx,num3
		call gcd
		; find lcm
		mov ax,lcmn
		mov bx,num3
		call lcm

		;output
		printm oprompt2
		mov bx,lcmn
		dec_output
		; ********************** LCM ************************************
		exitp

	main endp
end main

