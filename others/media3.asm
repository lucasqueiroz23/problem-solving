# Programa que recebe 3 inteiros e printa a média em um double

.text

main:
	jal ler_inteiros
	jal printar_media
	
	add $v0, $zero, 10 # sair do programa
	syscall

ler_inteiros:
	addi $t0,$zero,1 # (i) = 1
	add $a0,$zero,$zero # media = 0
	loop:
		addi $v0, $zero, 5 # indicar pro syscall que ele vai ler um inteiro
		syscall # ler inteiro x
		
		add $a0, $a0, $v0 # media += x
		
		addi $t0,$t0,1 # i++
		bne $t0,4,loop # if i != 4 goto loop
	jr $ra

printar_media:
	
	li $t0, 3 # t0 = 3
	mtc1 $t0, $f1 # $f1 = 3 
	cvt.s.w $f1, $f1 # agora, o processador entende que a palavra que f1 guarda é um float
	
	mtc1 $a0, $f12 # $f12 recebe o valor que a0 guarda
	cvt.s.w $f12, $f12 
	div.s $f12, $f12, $f1 # media /= 3
	
	addi $v0, $zero, 2 # printar float
	syscall
	
	jr $ra
