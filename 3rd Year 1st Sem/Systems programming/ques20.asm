;Write and test a program to Implement Linear search.
include mtab.asm

.model small
.stack 100h

.data
	prompts db 10,13,"Enter size of array: $"
	prompte db 10,13,"Enter elements of array: $"
	promptsr db 10,13,"Enter element to search: $"
	promptfound db 10,13,"element found at: $"
	promptnotfound db 10,13,"element not found $"
	arr dw 50 dup(?)
	s dw ?
.code
	
	main proc

		mov ax,@data
		mov ds,ax

		; display prompt for size
		printm prompts

		;accept size
		dec_input
		; bx has the size

		printm prompte

		mov s,bx
		lea si,arr
		mov cx,bx

		@array_input:
			pushall
			dec_input
			mov word ptr[si],bx
			popall

			inc si
			inc si

		loop @array_input

		; enter element to search
		printm promptsr
		dec_input

		;bx has the element to be searched
		lea si,arr
		mov cx,s

		@linear_search:
			cmp bx,word ptr[si]
			je @found

			inc si
			inc si
		loop @linear_search

		; not found case
		printm promptnotfound
		jmp @exit

		@found:
			printm promptfound
			mov bx,s
			sub bx,cx
			inc bx
			dec_output
			new_line

		@exit:
			exitp
	main endp
end main