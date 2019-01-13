;Write and test a program to Convert a Binary digit to Decimal and vice versa
include mtab.asm

.model small
.stack 100h

.data
	iprompt1 db "Enter two numbers: $"
	oprompt1 db "Their product is: $"
	num1 db ?
	num2 db ?
.code

	main proc
		mov ax,@data
		mov ds,ax
		xor bh,bh
		;input prompt
		printm iprompt1
		dec_input
		mov num1,bl
		xor bh,bh
		dec_input
		mov num2,bl
		xor bh,bh
		xor ah,ah
		mov al,num1
		mul bx
		
		mov bx,ax
		new_line
		printm oprompt1
		dec_output

		exitp

	main endp
end main