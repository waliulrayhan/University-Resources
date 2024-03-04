.data
	array: .space 100
	ArraySize: .asciiz "Enter number of the size of the Array(not greater than 25): "
	inputMsg: .asciiz "Enter the value of the elements of the array: "
	outputMsg: .asciiz "Minimum number of the array: "
.text
main:
	# print ArraySize message
	li $v0, 4
	la $a0, ArraySize
	syscall
	
	#Take ArraySize
	li $v0, 5
	syscall
	move $t5, $v0 # $t5= number of element
	
	#message for taking value from user
	li $v0, 4
	la $a0, inputMsg
	syscall

	addi $s0, $zero, 0 # for array index $s0=0
	addi $s1, $zero, 1 # loop counter i=1,  $s1=1
	
	#this loop for taking number of array
	input:
		bgt $s1, $t5, CheckLoop
	
		#take value from user
		li $v0, 5
		syscall
		move $t1, $v0
	
		#value store in array
		sw $t1, array($s0) #array[0]=$t1
		addi $s0, $s0, 4
		addi $s1,$s1,1  # i=i+1
		j input
	
	CheckLoop:
		addi $s0,$zero,0  # array index
		addi $s1,$zero,0  # loop counter i=0
		lw $t3, array($s0) # min in $t3  (min=array[0])
	
	findmin:
		addi $s1,$s1,1 # i=1
		beq $s1, $t5, Exit #if i==ArraySize, go to Exit
		addi, $s0, $s0, 4 #index+=4
		lw $t4, array($s0) #t4=arr[1] (2nd to last element)
	
		#check like if(min<arr[i])
		slt $t0, $t3, $t4   # if(min<arr[i]), $t0=1  else if(min>arr[i]), $t0=0
	
		#if before statment is true
		beqz $t0 min #if min>arr[i], goto min
		j findmin #go to findmin
	
		#minimum value put into min($t3)
		min:
			move $t3, $t4 #min in t3
			j findmin
	
	Exit:
		#message for minimum number
		li $v0, 4
		la $a0, outputMsg
		syscall
	
		#print the minimum number
		li $v0, 1
		move $a0, $t3 #the minimum number in t3
		syscall
	
		#successfully exit
		li $v0, 10
		syscall
