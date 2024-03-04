DATA SEGMENT
  X DW 04H          ; Define a 16-bit variable X with initial value 4 (Dividend)
  SQUARE DW ?       ; Define a 16-bit variable SQUARE to store the square of X
  CUBE DW ?         ; Define a 16-bit variable CUBE to store the cube of X
DATA ENDS

CODE SEGMENT
  ASSUME CS:CODE, DS:DATA

START:
  MOV AX, DATA      ; Load the data segment into AX
  MOV DS, AX        ; Move the data segment to DS

  MOV AX, X         ; Move the value of X into AX (Dividend)
  MOV BX, X         ; Move the value of X into BX (Multiplier)

  MUL BX            ; Multiply AX by BX (AX = AX * BX) to calculate the square of X
  MOV SQUARE, AX    ; Store the result (square) in the SQUARE variable

  MUL BX            ; Multiply AX by BX (AX = AX * BX) to calculate the cube of X
  MOV CUBE, AX      ; Store the result (cube) in the CUBE variable

  MOV AH, 4CH       ; Function to exit the program
  INT 21H

CODE ENDS
END START
