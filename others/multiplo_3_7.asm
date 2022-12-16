# ler um inteiro e determinar se ele é múltiplo de 3 e 7.
.data
mensagemMultiplo: .asciiz "MULTIPLO\n"
mensagemNaoMultiplo: .asciiz "NAO E MULTIPLO\n"
.text

main:
	li $v0, 5
	syscall
	
	move $a0, $v0
	
	jal definir_multiplicidade_3
	jal definir_multiplicidade_7
	
	and $t0, $s0, $s1
	beq $t0, 1, printar_multiplo
	
	la $a0, mensagemNaoMultiplo
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
	
definir_multiplicidade_3:
	li $t0,3
	div $a0,$t0
	mfhi $s0
	slti $s0, $s0, 1
	
	jr $ra

definir_multiplicidade_7:
	li $t0,7
	div $a0,$t0
	mfhi $s1
	slti $s1, $s1, 1
	
	jr $ra	
	
printar_multiplo:
	la $a0, mensagemMultiplo
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
	