# Programa que deve ler dois numeros e printar a soma deles na tela
# Feito por Lucas Henrique Lima de Queiroz no dia 25/11/2022


main:
	jal ler_inteiros
	
	jal printar
	j exit



ler_inteiros:
	move $t0, $zero #t0 = 0
	move $a0, $zero #a0 = 0
	
	scan:
		li $v0, 5 # indicar pro syscall que ocorerrá uma leitura de inteiros
		li $t1, 2 # t1 = 2, que é o número de inteiros que o programa vai ler.
		
		syscall
		add $a0, $a0, $v0 # a0 += v0
		
		addi $t0, $t0, 1 # t1++;
		bne $t0, $t1, scan # if(t1!=t0), ler novamente um inteiro
		
		jr $ra # caso tenha escaneado os dois valores, ir pra próxima linha
		

printar:
	li $v0, 1	#indicar pro syscal que ele deve printar um inteiro
	syscall
	jr $ra # após printar o inteiro, ir pra próxima linha

exit:
	li $v0, 10 #indicar pro syscall que ele vai finalizar o programa
	syscall	
	