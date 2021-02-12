.data

input_size: .asciiz "\nEnter the number of Terms : "
input_numbers: .asciiz "\nEnter the Array Element : \n"
num_search: .asciiz "\nEnter the Element to be searched: "
found: .asciiz "\nThe Element is present in the Array at Position: "
not_found: .asciiz "\nElement not found in the Array."
arr: .word 0 #array declaration

.text

.globl main

main:
	li $v0, 4		
	la $a0, input_size		# print the array message
	syscall

	li $v0, 5			# read the array number from the user
	syscall

	addi $t0, $v0, 0		# number of elements=$t0 
	addi $t1, $zero, 0		# t1=i=0    & t0 = size of array  
	
	li $v0, 4			
	la $a0, input_numbers		# print the array numbers
 	syscall

	la $s1, arr			# array adress= $s1
	
# this loop to enter the array numbers
input_loop:				
	beq $t1, $t0, exit_input	# if t1(i) = size if array exit from the while loop 
	li $v0,5			# read all numbers of array from user 
	syscall			
	sw $v0, 0($s1)			# store the value in the s1 variable
	addi $s1, $s1, 4		# s1 = s1 + 4
	addi $t1, $t1, 1		# i = i + 4
	j input_loop			# recursion loop (function call)
	
exit_input:
	#input for searching elements.. $a3=number to be searched
	li $v0, 4
	la $a0, num_search		# print (enter the value to be search)
	syscall
	
	li $v0, 5			# read the value (search) from the user 
	syscall 
	
	# Our inputs
	addi $a3, $v0, 0		# a3 = number to be searched
	la $a0, arr			# a0 = array
	addi $a1, $zero, 0		# a1 = First 
	addi $a2, $t0, -1		# a2 = Last
	
	jal binary_search		#function call
	#back to the main from funtion
	addi $t7, $zero, -1		 # t7 = -1
	beq $v1, $t7, nott		# if v1 == t7 call the function nott
	li $v0, 4			
	la $a0, found			# print that the element that be searched is in the array 
	syscall
	li $v0, 1
	addi $a0, $v1, 0		# print the position of the element 
	syscall
	li $v0, 10
	syscall

nott:
	li $v0, 4
	la $a0, not_found
	syscall
	li $v0, 10
	syscall

binary_search:
	
	la $a0, arr			# a0 = array
	addi $s2, $zero, 0		# s2 = 0 = middle
	slt $t1, $a2, $a1		# t1 = 1 if ( a2 < a1 )    while (first < last) 
	beq $t1, $zero, if1		# if ( t1 == 0 ) call function (if1)
	addi $v1, $zero, -1		# v1 += -1  
	jr $ra
	
if1:
	add $s2, $a2, $a1		# s2 = a2 + a1 ( middle = last + first )  
	
	addi $t9, $zero, 2		# t9=2 so that i could divide mid with by 2
	div $s2, $t9			# s2 / 2  ( div the middle on 2 )
	mflo $s2 			# move from LOW to s2
	mflo $s3			# move from LOW to s3
	mul $s3, $s3, 4 		# s3 = 4 * s3
	add $a0, $a0, $s3		# array (a0) = a0 +s3
	lw $s4, 0($a0)			# s4 = the first elemnt in array
	bne $s4, $a3, if2		# if array(i) in not equal the searched number then call if2
	addi $v1, $s2, 1		# vi = s2 + 1
	jr $ra
	 
if2:
	slt $t5, $a3, $s4		# t5 = 1 if ( a3 < s4 )
	beq $t5, $zero, else		# if ( t5 = 0 ) call function else 
	addi $a2, $s2, -1		# a2 = s2 -1
	addi $sp, $sp, -4		# sp = sp - 4
 	sw $ra, 0($sp)			
	jal binary_search

	j exit				# jump to function exit 
	
else:
	addi $a1, $s2, 1		# a1 = s2 +1 
	addi $sp, $sp, -4		# sp = sp - 4
	sw $ra, 0($sp)		
	jal binary_search
	j exit				# jump to function exit 
	
exit:
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra
