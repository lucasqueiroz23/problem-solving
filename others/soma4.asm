# soma de 4 inteiros
	

main:
	add $t0, $zero, $zero # t0 = 0
	addi $a0, $zero, 0 # a0 = 0
	j soma_inteiros


ler_inteiro:
	addi $v0, $zero, 5
	syscall
	add $a0, $a0, $v0
	
	jr $ra
	
	
soma_inteiros:
	beq $t0,4,exit
	addi $t0, $t0, 1
	jal ler_inteiro

	
	j soma_inteiros

print:
	addi $v0, $zero, 1
	syscall
	
	jr $ra

exit:
	jal print
	add $v0, $zero, 10
	syscall
