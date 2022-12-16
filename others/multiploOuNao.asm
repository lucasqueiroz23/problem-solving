# ler dois numeros inteiros e printar se o primeiro é multiplo do segundo

.data
mensagemMultiplo: .asciiz "MULTIPLO\n"
mensagemNaoMultiplo: .asciiz "NAO E MULTIPLO\n"

.text
main:
	jal ler_inteiros
	jal definir_divisibilidade
	beq $s2, 0, printarMultiplo
	
	la $a0, mensagemNaoMultiplo
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
	
ler_inteiros:
	li $v0, 5
	syscall
	
	move $s0, $v0
	
	li $v0, 5
	syscall
	
	move $s1, $v0
	
	jr $ra

definir_divisibilidade:
	div $s0, $s1
	mfhi $s2
	jr $ra

printarMultiplo:
	
	la $a0, mensagemMultiplo
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
	