.model small
.stack 100h

.data  
tempb dw ?
tempc dw ?

.code
main proc
	mov ax, @data                ; initialize ds
	mov ds, ax

	mov bx,1
	mov cx,99

	loop1:

		mov tempb,bx
		mov tempc,cx

		; print bx
		call decimal_output
		; print space
		mov ah,02
		mov dl,' '
		int 21h

		; print cx
		mov bx,tempc			;bx=tempc=cx
		call decimal_output

		; move back
		mov bx,tempb
		mov cx,tempc

		;print new line
		mov ah,02
		mov dl,','
		int 21h

		inc bx
		inc bx

		dec cx
		dec cx

		cmp bx,51

		jne loop1

	mov ah, 4ch                               ;return control to dos
	int 21h

main endp


;**************************************************************************;
 ;---------------------------  decimal_output  -----------------------------;
 ;**************************************************************************;

 decimal_output proc
   ; this procedure will display a decimal number
   ; input : bx
   ; output : none
   ; uses : main

   cmp bx, 0                      ; compare bx with 0
   jge @start                     ; jump to label @start if bx>=0
   mov ah, 2                      ; set output function
   mov dl, "-"                    ; set dl='-'
   int 21h                        ; print the character

   neg bx                         ; take 2's complement of bx

   @start:                        ; jump label

   mov ax, bx                     ; set ax=bx
   xor cx, cx                     ; clear cx
   mov bx, 10                     ; set bx=10

   @repeat:                       ; loop label
     xor dx, dx                   ; clear dx
     div bx                       ; divide ax by bx
     push dx                      ; push dx onto the stack
     inc cx                       ; increment cx
     or ax, ax                    ; take or of ax with ax
   jne @repeat                    ; jump to label @repeat if zf=0

   mov ah, 2                      ; set output function

   @display:                      ; loop label
     pop dx                       ; pop a value from stack to dx
     or dl, 30h                   ; convert decimal to ascii code
     int 21h                      ; print a character
   loop @display                  ; jump to label @display if cx!=0

   ret                            ; return control to the calling procedure
 decimal_output endp

end main