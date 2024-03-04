.model small
.stack 100h

.data
    number dw 26      ; Change this value to check for different numbers
    even_msg db 'The number is even.','$'   ; String for even message
    odd_msg  db 'The number is odd.','$'    ; String for odd message

.code
    mov ax, @data
    mov ds, ax

    ; Load the number to be checked into AX
    mov ax, number

    ; Check if the number is odd or even
    test ax, 1         ; Bitwise AND with 1 to check the least significant bit (LSB)
    jnz number_odd    ; Jump if the result is not zero (number is odd)

    ; If the least significant bit is zero, the number is even
    ; Print the even message.
    mov ah, 09h        ; DOS function to print a string
    lea dx, even_msg   ; Load the address of the even message
    int 21h            ; Call the DOS interrupt
    jmp end_program   ; Jump to end the program

number_odd:
    ; If the least significant bit is one, the number is odd
    ; Print the odd message.
    mov ah, 09h        ; DOS function to print a string
    lea dx, odd_msg    ; Load the address of the odd message
    int 21h            ; Call the DOS interrupt

end_program:
    ; Exit the program
    mov ah, 4Ch
    int 21h

end
