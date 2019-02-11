;Write and test a program to Convert a Binary digit to Decimal and vice versa
include mtab.asm

.model small
.stack 100h

.data
	iprompt1 db "Enter binary number: $"
	iprompt2 db "Enter decimal number: $"

	oprompt1 db "Equivalent decimal number: $"
	oprompt2 db "Equivalent binary number: $"

.code

	main proc
		mov ax,@data
		mov ds,ax

		;******************** BINARY TO DECIMAL *******************
		;input
		printm iprompt1

		bin_input	; binary number in bx
		
		;output
		new_line
		printm oprompt1
 		dec_output
 		;***********************************************************

 		;******************** DECIMAL TO BINARY *******************
		;input
		new_line
		printm iprompt2

		dec_input	; binary number in bx
		
		;output
		new_line
		printm oprompt2
 		bin_output
 		;***********************************************************

		exitp

	main endp
end main