#Problem7 : Print sum of even and odd numbers from 1 to 5 using loop

.data
	Even: .asciiz "Sum of Even numbers: "
	Odd: .asciiz "\nSum of Odd numbers: "
.text
main:

	li $t0, 0 # initial even sum = 0
	li $t1, 0 # initial odd sum = 0
	
	li $s2, 2 # will be use for finding even & odd
	
	li $s0, 0 # initial number $s0=number
  
	
for_loop:
	beq $s0, 5, Exit # add the range , here the range is 1 to 5
	addi $s0, $s0, 1
	
	div $s0, $s2 # s0/s2 
	# 5/2 lo=2 hi=1
	
	mfhi $s3 #store reminder

	#if reminder = 0, then jump even_sum level
	beq $s3, 0, even_sum
	j odd_sum #else jump odd_sum level
	j for_loop
	
even_sum:
	add $t0, $t0, $s0 # t0 = t0 + s0 (here value of s0 is even)
	j for_loop

odd_sum:
	add $t1, $t1, $s0 # t1 = t1 + s0 (here value of s0 is odd)
	j for_loop
Exit:
	#Print "Sum of even numbers: " stored in Even
	li $v0, 4
	la $a0, Even
	syscall

	#print even number sum stored in $t0
	li $v0, 1
	move $a0, $t0
	syscall


	#Print "Sum of odd numbers: " stored in Odd
	li $v0, 4
	la $a0, Odd
	syscall


	#print odd number sum stored in $t1
	li $v0, 1
	move $a0, $t1
	syscall

	#successfully exit
	li $v0, 10
	syscall	
