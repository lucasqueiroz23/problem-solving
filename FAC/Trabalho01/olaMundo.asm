# Programa que printa "Ola Mundo" na tela, com quebra de linha no final.
# Feito por Lucas Henrique Lima de Queiroz no dia 25/11/2022

.data
mensagem: .asciiz "Ola Mundo\n"
.text

main:
	la $a0, mensagem # colocar no registrador $a0 a mensagem 
	li $v0, 4 # indicar pro syscall que ele deve printar uma string, no caso, a que está em $a0
	syscall 
	
	j exit
	
exit:
	addi $v0, $zero, 10 # indicar pro syscall que ele vai chamar a exit
	syscall