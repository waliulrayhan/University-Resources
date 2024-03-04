.data
ms1: .asciiz "Enter the value of n: "
comma: .asciiz ", "

.text
main:


#printing the message ms1
li $v0,4
la $a0,ms1
syscall

#taking the input
li $v0,5
syscall
move $s0,$v0

li $t0,1

#looping

loop: bgt $t0,$s0,Exit #bgt = branch greater than. If bgt is false than jump out from the loop

li $v0,1
move $a0,$t0
syscall

beq $t0,$s0, notComma # not printing comma for the last element
#printing comma
li $v0,4
la $a0,comma
syscall

#incrementing by 1
addi $t0,$t0,1

j loop


notComma:
j Exit

#Successfully exit
Exit:
li $v0, 10
syscall
