;Write and test a program to print pairs of even numbers where the summation of the numbers in each pair is 100.
include mtab.asm

.model small
.stack 100h
.data
	tempb dw ?
	tempc dw ?
.code
	main proc

		mov ax,@data
		mov ds,ax

		mov bx,0
		mov cx,100

		@print_loop:
			mov tempb,bx
			mov tempc,cx

			dec_output
			space

			mov bx,tempc
			dec_output
			new_line

			mov bx,tempb
			mov cx,tempc

			inc bx
			inc bx

			dec cx
			dec cx

			cmp bx,52
		jle @print_loop
		exitp

	main endp
end main




