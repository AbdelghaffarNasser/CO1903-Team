.data
msc: .asciiz "Enter the number of the sort that you want to use \nPress 1 for Merge Sort\nPress 2 for Selection Sort\nPress 3 for Bubble Sort\n"
prompt: .asciiz  "\nEnter your characters/integers: "  # Prompt asking for user input
newLine: .asciiz "\n"                               # Newline character
theString: .asciiz " "                              # A fifty character string initially filled with whitespace

msc2: .asciiz "enter the number of characters/integers"

.text
main:

    la $a0, msc     # Load address of prompt from memory into $a0
    li $v0, 4         # Load Opcode: 4 (print string) 
    syscall           # Init syscall
    
    
    li $v0, 5			# read the array number from the user
    syscall
    
    addi $t0, $v0, 0		# number of elements=$t0 

    beq $t0,3,Bubble              #IF ($t0==3) call Bubble fun
    
    j exit
    
Bubble:
    
    
    la $a0, msc2    # Load address of prompt from memory into $a0
    li $v0, 4         # Load Opcode: 4 (print string) 
    syscall           # Init syscall
     
    li $v0, 5			# read the array number from the user
    syscall
    addi $t7, $v0, 0		# number of elements=$t0 

    la $a0, prompt    # Load address of prompt from memory into $a0
    li $v0, 4         # Load Opcode: 4 (print string) 
    syscall           # Init syscall
    
    

    la $a0,theString  # Load address of theString into syscall argument a0
    addi $a3,$t7,1      
    move $a1,$a3        # Load sizeOfInput+1 into syscall argument a1
    li $v0,8          # Load Opcode: 8 (Read String)
    syscall

    move $s7,$t7         # s7 upper index ,Define total num of chars
    
    jal sort
    jal print
    j exit


sort:   

    add $t0,$zero,$zero  #Initialize incrementer for outerloop
    la $s0, theString    # Load base address to theString into $t0
    add $t6,$zero,$zero  # Set index i = 0 ($t6)


    loop:   #  Outer Loop

        beq $t0,$s7,done  #Check for sentinal val and if true branch to done


        sub $t7,$s7,$t0   # Initialize upper bound of inner loop ( size - i - 1 ) 
        addi $t7,$t7,-1


        add $t1,$zero,$zero   #  Initialize incrementer for inner loop

        jLoop:   #  Inner Loop

            beq $t1,$t7,continue #  Check for sentinal val and if true branch to continue


            add $t6,$s0,$t1 
            lb  $s1,0($t6)  #Load Array[i]
            lb  $s2,1($t6)  #Load Array[i+1]

            sgt $t2, $s1,$s2 #  If ascii(Array[i]) > ascii(Array[i+1]) then swap and store

            beq $t2, $zero, inc  #  Else,  don't swap and store
            sb  $s2,0($t6)
            sb  $s1,1($t6)

            inc:

            addi $t1,$t1,1 #  increment and Jump back 
            j jLoop

        continue:

        addi $t0,$t0,1   #  increment and Jump back 
        j loop   # calling loop fun

print: #Prints whatever is stored inside theString

    la $a0,newLine   # Print a new line
    li $v0,4         
    syscall 

    add $t6,$zero,$zero # Set index i = 0 $t6

    lprint:

        beq $t6,$s7,done  #Check for sentinal val and if true

        #  Load Array[i] into t1 and print
        add $t1,$s0,$t6 
        lb $a0, 0($t1)  # Load argument
        li $v0, 11      # Load opcode
        syscall         # Call syscall

        addi $t6,$t6,1  #  increment and Jump back 
        j lprint        #excute the fun again

done:
    jr $ra  #continue the excution after calling the function 
exit:
            
