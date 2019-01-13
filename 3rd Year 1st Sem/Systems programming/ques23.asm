include mtab.asm

.model large
.stack 100
.data
	prompt1 db 'press left mouse button$'
	prompt2 db 'hello$'

.code
	main proc
		mov ax,@data
		mov ds,ax

	;	mov dx,offset prompt1
	;	mov ah,09h
	;	int 21h
	;	mov ah,02h
		;mov dl,0dh
		;int 21h
		;mov dl,0ah
		;int 21h

		mov ah,00h
		mov al,13h
		int 10h

		xor cx,cx
		xor dx,dx

		mov ah,00h
		int 33h

		left_clk:
			xor bx,bx
			mov ax,3
			int 33h
			cmp bx,1
			jne left_clk

			;mov dl,dh
			;mov dh,ch
			;mov bh,0
			;mov ah,2
			;int 10h
			;mov dx,offset prompt2
			;mov ah,09h
			;int 21h

			pushall
			dec_output cx
			popall
			mov ah,02h
		mov dl,20h
		int 21h
			pushall
			dec_output dx
			popall

		mov ah,4ch
		int 21h
	main endp
end main