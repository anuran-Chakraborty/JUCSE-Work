.model small
.stack 100h

.data
	msg db"Enter a character $"

.code
	main proc

		;point to data segment
		mov ax,@data
		mov ds,ax

		;display prompt
		lea dx,msg
        mov ah,09h
        int 21h

        ;accept the character
        mov ah,01h
        int 21h

        
        


	endp
end main 