; MASM Program to implement binary search
include mtab.asm

.model small
.stack 100h

array_output macro arr
	local @array_print
	;printing the array
	lea si,arr
	mov cx,s
	@array_print:
		mov bx,word ptr[si]
		mov temp,cx
		dec_output
		space
		inc si
		inc si
		mov cx,temp
	loop @array_print
endm

.data
	prompts db 10,13,"Enter size of array: $"
	prompte db 10,13,"Enter elements of array: $"
	promptsr db 10,13,"Enter element to search: $"
	promptfound db 10,13,"element found at: $"
	promptnotfound db 10,13,"element not found $"
	wrong_key db 10,13,"Invalid key entered: $"

	arr dw 50 dup(?)
	s dw ?
	strt dw ?
	stop dw ?
	min_idx dw ?
	temp dw ?
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

		call sort
		; enter element to search
		printm promptsr
		dec_input

		;bx has the element to be searched
		lea si,arr
		mov cx,s
		dec cx
		mov strt,00h
		mov stop,cx

		;************* BINARY SEARCH ********************
		@binary_search:
			;find out the middle index
			lea si,arr
			mov cx,stop
			add cx,strt
			shr cx,1		;cx is the index for the middle element
			add si,cx	;si=si+cx
			add si,cx

			;*************
			push bx
			push cx
			mov bx,cx
			call deci_output
			pop cx
			pop bx
			space

			push bx
			push cx
			mov bx,word ptr[si]
			call deci_output
			pop cx
			pop bx
			new_line
			;*************
			call ent

			cmp bx,word ptr[si]
			je @found		; if middle element then found

			jg @greater

			;if less
			@lesser:
				dec cx
				mov stop,cx
				jmp @compare

			@greater:
				inc cx
				mov strt,cx

			@compare:
				mov cx,stop
				cmp cx,strt

		jge @binary_search

		;************************************************

		; not found case
		printm promptnotfound
		jmp @exit

		@found:
			printm promptfound
			mov bx,cx
			inc bx
			dec_output
			new_line

		@exit:
			exitp
	main endp


	deci_output proc

		dec_output
		ret
	deci_output endp

	ent proc
		;prompt for enter
		;********** pressing enter will show next step esc will exit ************
		@error_enter:
			mov ah,01h
			int 21h

			cmp al,1bh	;check if esc is pressed
			je @exit2
			cmp al,0dh
			je @compare2
			printm wrong_key
		jmp @error_enter
		;************************************************************************
		@compare2:
			ret

		@exit2:
			exitp
	ent endp


	sort proc
		;************** sorting ****************************
		lea si,arr
		mov cx,s
		dec cx
		@outer_loop:
			mov dx,cx				; dx is the inner loop counter
			mov di,si
			inc di
			inc di
			mov min_idx,si
			push si
			@inner_loop:
				mov si,min_idx
				mov bx,word ptr[si]
				cmp word ptr[di],bx
				jge @incr
				; else set min_idx the elements
				mov min_idx,di
				@incr:
				inc di
				inc di
				dec dx
			jnz @inner_loop

			;swap
			pop si
			mov di,min_idx
			mov bx,word ptr[di]
			xchg word ptr[si],bx
			mov word ptr[di],bx
			inc si
			inc si

			push si
			push cx
			; here keyboard input inserted
			@next_iter:
			pop cx
			pop si

		loop @outer_loop
		ret
		;***************************************************
	sort endp

end main