#Using Recursion find out factorial of an integer.
#n! = n*(n-1) *(n-2) *(n-3) *(n-4) *……. * 3*2*1
.data
    input: .asciiz "Enter an integer n: "
    output: .asciiz "Factorial of the given number is = "
    negative: .asciiz "\nFactorials do exist for negative number ."
       
.text
    li        $v0, 4
    la        $a0, input
    syscall
    #input
    li        $v0, 5
    syscall
    move      $a0, $v0   #a0=n
    ############################
    
    slt $t5,$a0,$zero
    
    beq $t5,1,exit
    
    ############################
    # function call
    jal      factorial       # save next instruction address to $ra 					and jump factorial
    move      $t0, $v0        # $t0 = $v0
    
    li        $v0, 4
    la        $a0, output
    syscall
    
    # print the result
    li        $v0, 1        # system call #1 - print int
    move      $a0, $t0      # $a0 = $t0
    syscall 
   
    # return 0 and exit
    li        $v0, 10        # $v0 = 10
    syscall
factorial:
    addi    $sp, $sp, -8
    # save $s0 and $ra
    sw      $s0, 4($sp)
    sw      $ra, 0($sp)
    bne     $a0, 0, else     #if $a0!=0 go to else
    addi    $v0, $zero, 1    # return 1
    j fact_return

else:
    # backup $a0
    move    $s0, $a0
    addi    $a0, $a0, -1 # n -= 1
    jal     factorial
    mult    $s0, $v0 # return x*Fact(x-1) 
    mflo    $v0      #$lo
    
fact_return:
    lw      $s0, 4($sp)
    lw      $ra, 0($sp)
    addi    $sp, $sp, 8
    jr      $ra




exit:
li        $v0, 4
la        $a0, negative
syscall

#successfully termination
li $v0,10
syscall