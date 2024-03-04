.data
ms1: .asciiz "Enter your first number: "
ms2: .asciiz "Enter your second number: "
ms3: .asciiz "Yours entered numbers are equal."
ms4: .asciiz "Your entered number are not equal."

.text
main:

#printing ms1
li $v0, 4
la $a0, ms1
syscall

#taking the input
li $v0,5
syscall
move $s0,$v0
# storing the number to a temp regi
add $t0,$s0,$0 

#printing ms2
li $v0, 4
la $a0, ms2
syscall

#taking the input
li $v0,5
syscall
move $s0,$v0

# storing the number to a temp regi
add $t1,$s0,$0

#checking if t0 == t1 else execute "Condition"
bne $t0,$t1,condition

#print message if numbers are equal
li $v0, 4
la $a0, ms3
syscall
j Exit


condition:
#print the message if numbers are not equal
li $v0, 4
la $a0, ms4
syscall


#Successfully exit
Exit:
li $v0, 10
syscall
