# Programa que lê um inteiro e diz se ele é primo ou não. Feito no dia 24/10/2023 por Lucas Henrique Lima de Queiroz.

.data 
entrada_invalida: .asciiz "Entrada invalida.\n"
sim: .asciiz "sim\n"
nao: .asciiz "nao\n"

.text
main:
	li $v0, 5 # read integer
	syscall

	
	slti $t0, $v0, 1 # if vo < 1 
	beq $t0, 1, invalido
	beq $v0, 1, nao_primo
	
	move $v1, $v0
	
	mtc1 $v0, $f1
	cvt.s.w $f1, $f1
	sqrt.s $f1,$f1
	cvt.w.s $f1,$f1
	mfc1 $v0, $f1
	beq $v0, 1, primo # caso = 2
	li $t0, 2 #count = 2
	addi $v0, $v0, 1
	loop:
		div $v1,$t0
		mfhi $t1
		beq $t1, 0, nao_primo
		addi $t0, $t0, 1
		slt $t3, $t0, $v0
		beq $t3, 1, loop
primo:
	la $a0, sim
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall

invalido:
	la $a0, entrada_invalida
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall

nao_primo:
	la $a0, nao
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
	
