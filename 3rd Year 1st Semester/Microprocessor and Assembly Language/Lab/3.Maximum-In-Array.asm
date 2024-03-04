.model small
.stack 100h

.data
    ARRAY_SIZE  equ 10
    array       db 1, 5, 2, 3, 8, 6, 4, 7, 9, 10
    max_number  db ?

.code
    mov ax, @data
    mov ds, ax

    ; Initialize max_number with the first element of the array
    mov al, array
    mov max_number, al

    ; Loop through the array to find the maximum number
    mov cx, ARRAY_SIZE - 1 ; Number of iterations required (10-1 = 9)
    mov si, 1              ; Starting index for the loop (second element of the array)

loop_start:
    mov al, array[si]      ; Load the current array element into AL
    cmp al, max_number     ; Compare with the current max_number
    jle not_update_max     ; Jump if AL <= max_number

    ; If AL is greater than max_number, update the max_number
    mov max_number, al

not_update_max:
    ; Continue to the next element
    inc si
    loop loop_start

    ; At this point, the maximum number is stored in max_number

    ; Exit the program
    mov ah, 4Ch
    int 21h
end
