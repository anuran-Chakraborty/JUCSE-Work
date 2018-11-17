;Write and test a MASM program to Implement Selection Sort. Show the steps. 
;Each step will be succeeded by “Enter” key. The Program will terminate when the “Esc” key is pressed.
include mtab.asm

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

.model small
.stack 100h

.data
	prompts db 10,13,"Enter size of array: $"
	prompte db 10,13,"Enter elements of array: $"
	promptsr db 10,13,"The sorted array is: $"
	wrong_key db 10,13,"Invalid key entered: $"
	arr dw 50 dup(?)
	s dw ?
	temp dw ?
	min_idx dw ?
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

		;********** array input ***************************
		@array_input:
			mov temp,cx
			dec_input
			mov word ptr[si],bx
			mov cx,temp
			inc si
			inc si

		loop @array_input
		;***************************************************

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

			array_output arr
			; here keyboard input inserted
			;********** pressing enter will show next step esc will exit ************
			@error_enter:
				mov ah,01h
				int 21h

				cmp al,1bh	;check if esc is pressed
				je @exit
				cmp al,0dh
				je @next_iter
				printm wrong_key
			jmp @error_enter
			;************************************************************************
			@next_iter:
			pop cx
			pop si

		loop @outer_loop

		;***************************************************

		;******* array output ***************************
		printm promptsr
		array_output arr
		;***************************************************
		@exit:
			exitp
	main endp
end main