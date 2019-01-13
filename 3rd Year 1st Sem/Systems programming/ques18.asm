.model medium
.stack 100h

.data
	prompt_1 	db 10,13,'enter the string : $'
	prompt_2 	db 10,13,'enter the substring to be deleted : $'
	prompt_3 	db 10,13,'the new string is : $'
	newline 	db 10,13,'$'

	;input string
	buffersize_1	db 51  				; 50 char + return
	inputlength_1 	db 0   				; number of read characters
	string        	db 51 dup(0) 		; actual buffer
	end_1 			db '$'
	index1 			db 0				;index for looping

	;input substring
	buffersize_2  	db 21  				; 20 char + return
	inputlength_2 	db 0   				; number of read characters
	substring     	db 21 dup(0) 		; actual buffer
	index2 			db 0				;index for looping

	;modified output string
	index3 		db 0					;index for looping
	newstring 	db 50 dup('$')
	
	;macro to display prompt and print string
	display macro msg
		mov ah,9
		lea dx,msg
		int 21h
	endm

	;macro for string input
	get_string macro buffer_
		mov dx, offset buffer_ 		; load our pointer to the beginning of the structure
		mov ah, 0ah 				; getline function
		int 21h


		mov si, offset buffer_ + 1	;move pointer to the input string size 
		mov cl, [ si ] 				;move input string size to cl
		mov ch, 0       			;clear ch to use cx
		inc cx 						
		add si, cx					;move pointer to the next byte of the last input
		mov al, '$'				
		mov [ si ], al 				;add '$' after the input string
	endm

	;macro for copynig character from input string to output string 
	string_copy macro
		mov di,offset newstring		; load our pointer to the beginning of the structure
		mov al,index3
		xor ah,ah 					;load the index in ax register
		add di,ax 					;go to the next location where the character is to be copied
		mov dl,[ si ]				
		mov [ di ],dl 				;copy from input string to output string
		inc al
		mov index3,al 				;increment the index
	endm

	;macro  to check whether two character of the input string and substring are same or not
	compare macro
		mov dl,[ si ]				; load the character of input string in dl
		mov di,offset substring
		mov al,index2
		mov ah,ah
		add di,ax					
		mov dh,[ di ]				; load the character of input substring in dh
		cmp dl,dh					; compare dl and dh
	endm

	

.code
	main proc
		mov ax,@data
		mov ds,ax

		display prompt_1
		get_string buffersize_1  			; input the string		

		display prompt_2
		get_string buffersize_2				; input the substring

		mov si,offset string 				; load our pointer to the beginning of the structure

		mov cl,inputlength_1 				; move length of the string in cl
		
		@loop1:
			mov di,offset substring 		; load our pointer to the beginning of the structure
			mov index2,0 					
			string_copy
			compare
			jne @label1 				

			mov bl,inputlength_2
			xor bh,bh
			dec bx
			
				@loop2:
					inc si
					dec cl
					inc index2
					string_copy	
					compare
					jne	@label1	
					dec bl
					jne @loop2

				;if the substring is present
				mov bl,inputlength_2 	;move substring length to bl
				mov al,index3 			; move new string index to al
				sub al,bl				; subtract bl from al
				mov index3,al 			; save al in new string index
			
		@label1:
		inc si
		loop @loop1

		@print:
		string_copy 					; add '$' after the output string
		display prompt_3
		display newstring				; display the output string

		mov ah,4ch
		int 21h

	main endp
end main