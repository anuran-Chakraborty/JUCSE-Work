;Write and test a program to Convert a Binary digit to Decimal and vice versa
include mtab.asm

.model small
.stack 100h

.data
	iprompt1 db "Enter binary number: $"
	iprompt2 db "Enter hexadecimal number: $"

	oprompt1 db "Equivalent hexadecimal number: $"
	oprompt2 db "Equivalent binary number: $"

.code

	main proc
		mov ax,@data
		mov ds,ax

		;******************** BINARY TO HEXADECIMAL *******************
		;input
		printm iprompt1

		bin_input	; binary number in bx
		
		;output
		new_line
		printm oprompt1
 		hex_output
 		;***********************************************************

 		;******************** HEXADECIMAL TO BINARY *******************
		;input
		new_line
		printm iprompt2

		hex_input	; binary number in bx
		
		;output
		new_line
		printm oprompt2
 		bin_output
 		;***********************************************************

		exitp

	main endp
end main