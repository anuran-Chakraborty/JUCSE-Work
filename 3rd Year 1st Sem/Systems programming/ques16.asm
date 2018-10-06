;Write and test a program to divide a 16 bit number by a 8 bit number.
include mtab.asm
.model small
.stack 100h

.data
	iprompt1 db 10,13,"Enter 16 bit number: $"
	iprompt2 db 10,13,"Enter 8 bit number: $"
	oprompt1 db 10,13,"Quotient is: $"
	oprompt2 db 10,13,"Remainder is: $"
	num1 dw ?
.code
	
	main proc

		mov ax,@data
		mov ds,ax

		;input
		printm iprompt1
		hex_input

		mov num1,bx

		printm iprompt2
		hex_input

		mov ax,num1
		xor dx,dx
		div bx

		;output
		mov bx,ax
		mov num1,dx

		printm oprompt1
		pushall
		hex_output
		popall

		mov bx,num1

		printm oprompt2
		pushall
		hex_output
		popall

		exitp
	main endp
end main