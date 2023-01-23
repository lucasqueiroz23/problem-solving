# Programa que deve ler o tamanho de uma string, a própria string, e printar 1 se ela for
# um palíndromo e 0 caso contrário.
# Feito por Lucas Henrique Lima de Queiroz no dia 08/01/2023

.data
	palavra: .space 1028
.text
main:
	li $v0, 5 # read int
	syscall
	
	move $s0, $v0 # s0 = string length
	addi $a1, $s0, 2 # a1 = string length + null terminator + \n
	
	li $v0, 8 # read string for syscall
	
	la $a0, palavra # read string 'palavra' and store in a0
	syscall
	
	move $s1, $a0 # s1 = content of 'palavra'
	
	jal isPalindrome
	
	
	li $v0, 10 # exit program
	syscall
	
isPalindrome:
	addi $t0, $s0, -1 
	add $t0, $t0, $s1 # t0 = palavra[length-1];
	
	move $t4, $zero # t4 = 0
	div $t5, $s0, 2
	mflo $t5 # t5 = length/2
	
	
	loop:
		lb $t1, 0($s1) # t1 = palavra[i];
		lb $t2, 0($t0) # t2 = palavra[j];
		bne $t1, $t2, notPalindrome
		
		addi $s1, $s1, 1 # i++
		addi $t0, $t0, -1 # j--
		
		slt $t3, $t4, $t5
		addi $t4, $t4, 1
		beq $t3, 1, loop # if t4 < t5 goto loop
		
		li $v0, 1
		li $a0, 1 #if palindrome print 1
		syscall
	
		
		li $v0, 10 # exit program
		syscall
		
notPalindrome:
	li $v0, 1 
	li $a0, 0 # if not palindrome print 0
	syscall
	
	li $v0, 10 # exit program
	syscall
