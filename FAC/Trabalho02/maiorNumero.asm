# Programa que deve ler N números inteiros e printar o maior deles.
# Feito por Lucas Henrique Lima de Queiroz no dia 5/12/2022

# n => $s0
# maior => $s1

main:
	move $s1, $zero # maior = 0
	jal ler_n
	jal descobrirMaior
	jal printarMaior
	j exit

ler_n:
	addi $v0, $zero, 5 # read int
	syscall
	add $s0, $zero, $v0 # guardar n em $s0
	jr $ra

descobrirMaior:

	ler_primeiro_numero:
		addi $v0, $zero, 5 # read int
		syscall
		move $s1, $v0 # maior = primeiroNumeroLido
		
addi $t0, $zero, 1 # t0 = 1	
	
	loop:
		beq $t0, $s0, retornarParaRA #if(t0 == $s0) return;
		addi $t0, $t0, 1 # $t0++
		
		ler_inteiro:
			addi $v0, $zero, 5 # read int
			syscall
			
			slt $s2, $s1, $v0 # if( maior < numero) $s2 = true
			beq $s2, 1, toggleMaior # if $s2 = true, toggleMaior()
			j loop
			
toggleMaior:
	move $s1, $v0 # maior = numero
	j loop 

retornarParaRA:
	jr $ra

printarMaior:
	addi $v0, $zero, 1 # printar int
	add $a0, $s1, $zero # a0 recebe o maior valor
	syscall
	jr $ra

exit:
	addi $v0, $zero, 10 # fechar o programa 
	syscall
