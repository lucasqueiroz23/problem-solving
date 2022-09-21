#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *mensagem = malloc(3*1048576*sizeof(char));
	int numero=0,menor=-1,maior=-1;
	char caracter;
	scanf("%d %c",&numero,&caracter);
	numero = numero%(3*1048576);
	maior = numero;
	menor = numero;
	mensagem[numero] = caracter;

	while(scanf("%d %c",&numero,&caracter)!=EOF)
	{
		numero = numero%(3*1048576); ///geracao de hash
		if(numero>maior)
			maior = numero;
		if(numero<menor)
			menor = numero;

		if(mensagem[numero]!=caracter)
			mensagem[numero] = caracter;


	}
	for(int i = menor;i<=maior;i++)
		printf("%c",mensagem[i]);
	printf("\n");

	free(mensagem);
	return 0;
}
