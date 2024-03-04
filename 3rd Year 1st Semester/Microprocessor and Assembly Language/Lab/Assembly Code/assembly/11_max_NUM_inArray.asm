.data
	array: .space 100
	ArraySize: .asciiz "Enter number of Size of the Array (not greater than 25): "
	inputMsg: .asciiz "Enter the value of the elements of the array: "
	outputMsg: .asciiz "Maximum number of the array: "
.text
main:
	#asking size of the array by printing Arraysize
	li $v0, 4
	la $a0, ArraySize
	syscall
	
	#Taking ArraySize from user
	li $v0, 5 #5 for taking input
	syscall
	move $t5, $v0 #storing $t5= ArraySize
	
	#message for taking elements from user
	li $v0, 4
	la $a0, inputMsg
	syscall

	addi $s0, $zero, 0 # for array index $s0=0
	addi $s1, $zero, 1 # loop counter i=1,  $s1=1
	
	#this loop for taking number of array
	input:
		bgt $s1, $t5, CheckLoop #if counter>ArraySize, already entered all values
	
		li $v0, 5 #take value from user
		syscall
		move $t1, $v0
	
		#value store in array
		sw $t1, array($s0) #array[index]=$t1
		addi $s0, $s0, 4 #index+=4
		addi $s1,$s1,1  # i=i+1 //counter
		j input
	
	CheckLoop:
		addi $s0,$zero,0  # array index
		addi $s1,$zero,0  # loop counter i=0
		lw $t3, array($s0) # max in $t3  (max=array[0])
	
	findmax:
		addi $s1,$s1,1 # i=1
		beq $s1, $t5, Exit #if i==ArraySize, go to exit
		addi, $s0, $s0, 4 #s0=s0+4
		lw $t4, array($s0) #t4=array[1] (2nd to last element)
	
		#check like if(max<arr[i])
		slt $t0, $t3, $t4   # if(max<arr[i]), $t0=1  else if(max>arr[i]), $t0=0
	
		#if before statment is true
		bnez $t0 max #if t0!=0, max<arr[i], then go to max
		j findmax #else go to findmax
	
		#maximum value put into max($t3)
		max:
			move $t3, $t4 #max=arr[i]
			j findmax #goto findmax
	
	Exit:
		#message for maximum number
		li $v0, 4
		la $a0, outputMsg
		syscall
	
		#print the maximum number
		li $v0, 1 #for printing integers
		move $a0, $t3 #t3 is my maximum number
		syscall
	
		#successfully exit
		li $v0, 10
		syscall
