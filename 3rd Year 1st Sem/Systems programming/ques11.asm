;Write and test a program to Convert a Binary digit to Decimal and vice versa
include mtab.asm

.model small
.stack 100h

.data
	iprompt1 db "Enter two numbers: $"
	oprompt1 db "Their sum is: $"
	oprompt2 db "Their difference is: $"
	num1 dw ?
	num2 dw ?
.code

	main proc
		mov ax,@data
		mov ds,ax

		;input prompt
		printm iprompt1
		hex_input
		mov num1,bx

		hex_input
		mov num2,bx
		
		;********************** SUM **************************************
		printm oprompt1
		
		mov cx,num1
		add bx,cx

		jnc display

		carry_disp:
			;display carry
			mov ah,02h
			mov dl,'1'
			int 21h

		display:
			hex_output
		;********************** SUM **************************************

		;********************** DIFF **************************************
		new_line
		printm oprompt2
		
		mov bx,num1
		mov cx,num2
		sub bx,cx
		
		hex_output
		;********************** DIFF **************************************

		exitp

	main endp
end main