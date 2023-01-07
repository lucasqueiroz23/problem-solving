#include <stdio.h>
#include <stdlib.h>

void verificarQuantidadeDeAcertos(int n){
	char *gabarito = malloc((n+1)*sizeof(char));
	char *respostas = malloc((n+1)*sizeof(char));

	scanf("%s", gabarito);
	scanf("%s", respostas);

	int qtdAcertos = 0;

	for(int i = 0; i<n; i++){
		if(gabarito[i] == respostas[i])
			qtdAcertos++;
	}

	printf("%d\n",qtdAcertos);

	free(gabarito);
	free(respostas);
}

int main(){
	int n = 0;
	scanf("%d",&n);

	verificarQuantidadeDeAcertos(n);

	return 0;
}
