# Programa que recebe dois inteiros e printa o mdc e o mmc entre eles. Feito por Lucas Henrique Lima de Queiroz no dia 26/01/2023.

.data
mensagemInvalido: .asciiz "Entrada invalida.\n"
quebraLinha: .asciiz "\n"

.text
main:
	li $v0, 5
	syscall
	
	move $s0, $v0 # s0 = a
	
	li $v0, 5
	syscall
	
	move $s1, $v0 # s1 = b
	
	slti $t0, $s0, 2 # se a < 2, t0 = true
	slti $t1, $s1, 2 # se b < 2, t1 = true
	
	beq $t0, 1, entradaInvalida # se a < 1, entrada invalida
	beq $t1, 1, entradaInvalida # se b < 1, entrada invalida

obter_multiplo:
	mul $a1, $s0, $s1 # a1 = a * b 	

obterMDC:
	comparar_a_e_b:
		slt $t0, $s0, $s1 # if a < b, t0 = true
		slt $t1, $s1, $s0 # if a > b, t1 = true
		beq $t0, 1, b_maior
a_maior: # entra aqui sempre que a >= b
	move $s3, $s0 # s3 = maior
	move $s4, $s1 # s4 = menor
	j euclides
	
b_maior: # caso em q b eh maior que a
	move $s3, $s1 # s3 = maior
	move $s4, $s0 # s4 = menor

euclides:
	li $a0, 1 # resto(em a0 = 1)
	while:
		beq $a0, 0, fim_loop # if(resto == 0) goto fim_loop
		div $s3, $s4 # maior / menor, resto vai pro HI
		mfhi $a0 # resto = maior%menor;
		beq $a0, 0, fim_loop # if resto == 0, sai do loop
		move $s3, $s4 # maior = menor
		move $s4, $a0 # menor = resto
		
		j while
	
fim_loop:
	
	# agora, o mdc se encontra no s4. e o multiplo se encontra em a1.
	
	div $a1, $s4 # multiplo / mdc, quociente vai pro HI
	
	move $a0, $s4 # printar mdc
	li $v0, 1
	syscall
	
	la $a0, quebraLinha
	li $v0, 4
	syscall
	
	li $v0, 1 # printar mmc
	mflo $a0
	syscall
	
	
	li $v0, 10
	syscall
	
entradaInvalida:
	
	la $a0, mensagemInvalido
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
	
