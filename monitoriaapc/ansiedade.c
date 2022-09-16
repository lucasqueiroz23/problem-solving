#include <stdio.h>
#include <stdlib.h>

int acabouConsulta(int posicaoResposta)
{
	
	if(posicaoResposta == 10)
		return 1;

	return 0;
}

int main()
{
	int qtdTriagem = 0;
	char *resposta = malloc(4*sizeof(char));
	int numeroResposta = 0;
	int contaSim = 0;
	while(scanf("%s",resposta)!=EOF)
	{
		if(resposta[0] == 's' && resposta[1] == 'i' && resposta[2] == 'm')
		{
			contaSim++;
			
		}

		numeroResposta++;
		if(acabouConsulta(numeroResposta)){
			numeroResposta = 0;
			if(contaSim>=2)
				qtdTriagem++;
			contaSim = 0;
		}
	}

	printf("%d\n",qtdTriagem);

	free(resposta);
	return 0;
}
