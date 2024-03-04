.data
	message: .asciiz "Mymessage\n"
	integervalue: .word 1
	char: .byte 'm'
	newline: .asciiz "\n"

.text

	li $v0,4
	la $a0,char
	la $a1,newline
	syscall
	 
	li $v0,4
	la $a0,message
	syscall 
	
	li $v0,1
	lw $a0,integervalue
	la $a1,newline
	syscall
	 
	
	
