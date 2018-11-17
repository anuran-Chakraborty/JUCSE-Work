.model small
.stack 100h
.data
	msg1 db 10,13,'enter file name to be created $'
	msg2 db 10,13,'file is created$'
	msg3 db 10,13,'enter file name to be deleted $'
	msg4 db 10,13,'file is deleted$'
	msg5 db 10,13,'deletion error$'
	fnc db 50 dup(?)
	fnd db 50 dup(?)

.code
	pushall macro
		push ax
		push bx
		push cx
		push dx
	endm

	popall macro
		pop dx
		pop cx
		pop bx
		pop ax
	endm

	print macro arg
		mov dx,offset arg
		mov ah,09h
		int 21h
	endm

	readstr macro arg
		local readlp,exit
		mov di,offset arg
		readlp:
			mov ah,01h
			int 21h
			cmp al,13
			je exit
			mov [di],al
			inc di
			jmp readlp
		exit:
	endm

	main proc
		mov ax,@data
		mov ds,ax
		
		print msg1
		pushall
		readstr fnc
		popall

		crte:
			mov cx,0
			mov dx,offset fnc
			mov ah,3ch
			int 21h
			print msg2

		print msg3
		pushall
		readstr fnd
		popall

		dlte:
			lea dx,fnd
			mov ah,41h
			int 21h
			jc nfound
			print msg4
			jmp exit

		nfound:
			print msg5

		exit:
			mov ah,4ch
			int 21h
	main endp
end main