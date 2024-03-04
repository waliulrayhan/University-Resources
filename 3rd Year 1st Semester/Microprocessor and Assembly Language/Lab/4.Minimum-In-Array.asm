.model small
.stack 100h

.data
    ARRAY_SIZE  equ 10
    array       db 10, 50, 20, 35, 80, 5, 45, 30, 15, 25
    min_number  db ?

.code
    mov ax, @data
    mov ds, ax

    ; Initialize min_number with the first element of the array
    mov al, array
    mov min_number, al

    ; Loop through the array to find the minimum number
    mov cx, ARRAY_SIZE - 1 ; Number of iterations required (10-1 = 9)
    mov si, 1              ; Starting index for the loop (second element of the array)

loop_start:
    mov al, array[si]      ; Load the current array element into AL
    cmp al, min_number     ; Compare with the current min_number
    jge not_update_min     ; Jump if AL >= min_number

    ; If AL is less than min_number, update the min_number
    mov min_number, al

not_update_min:
    ; Continue to the next element
    inc si
    loop loop_start

    ; At this point, the minimum number is stored in min_number

    ; Exit the program
    mov ah, 4Ch
    int 21h
end
