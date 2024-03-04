.data
ms1: .asciiz "Enter your number: "
ms2: .asciiz "The number is Positive\n"
ms3: .asciiz "The number is Negative\n"

.text
main:
#printing the ms1
li $v0, 4
la $a0, ms1
syscall

#taking the input
li $v0,5
syscall
move $s0,$v0


slt $t0, $s0, $0 # if $s0 < 0 return 1 else return 0
beq $t0, 0, else_pos # if $t0 == 0 proceed else execute "else_pos"

#print message for Negative
li $v0, 4
la $a0, ms3
syscall
j Exit

#print message for Positive
else_pos:
li $v0, 4
la $a0, ms2
syscall


#Exit the program
Exit:
li $v0, 10
syscall
