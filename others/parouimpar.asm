# receber um inteiro e dizer se é par ou ímpar 
.data
mensagemPar: .asciiz "PAR\n"
mensagemImpar: .asciiz "IMPAR\n"
.text
main:
	li $v0, 5
	syscall
	
	li $t0, 2
	div $v0, $t0
	
	mfhi $t0
	
	beq $t0, 0, printar_par
	
	la $a0, mensagemImpar
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
printar_par:
	
	la $a0, mensagemPar
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall