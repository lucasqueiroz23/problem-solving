# recebe um salário, em float, e printa o salário acrescido de 25%
.data
const_1_25: .float 1.25
.text
main:
	jal ler_salario
	jal printar_salario_novo
	
	li $v0, 10 # sair do programa
	syscall

ler_salario:
	li $v0, 6 # ler float e guardar em $f0 
	syscall
	
	jr $ra

printar_salario_novo:
	l.s $f2, const_1_25 # colocar o valor 1.25 no coproc1 f2
	mul.s $f12, $f0, $f2  # f1*f2 = f1 * 1,25
	li $v0, 2 # imprimir float
	syscall
	
	jr $ra