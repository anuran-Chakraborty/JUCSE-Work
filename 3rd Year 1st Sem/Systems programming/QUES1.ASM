; Write and test a MASM program to Display your name and program title on the output screen.
.model small
.stack 100h

.data
        name1 db"Name: Anuran$"
        programTitle db"Program title: Ques1$"
.code
        mov ax,@data
        mov ds,ax

        ;display the name
        lea dx,name1
        mov ah,09h
        int 21h

        ;carriage return
        mov AH, 02h                  
        mov DL, 0DH
        int 21H

        ;line feed
        mov DL, 0AH               
        int 21H

        ;display program title
        lea dx,programTitle
        mov ah,09h
        int 21h

        ;exit
        mov ah,4Ch
        int 21h
end
