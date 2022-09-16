#include <stdio.h>
#include <stdlib.h>

int main()
{
	int tamanhoString = 0, n = 0;
	scanf("%d",&n);
	tamanhoString = 2*n;

	char *piramide = malloc((tamanhoString) * sizeof(char));
	piramide[tamanhoString-1] = '\0';

	for(int i = 0; i<tamanhoString-1;i++){
		piramide[i] = ' ';
	}

	piramide[n-1] = '*';
	printf("%s\n",piramide);
	int l = n-2, r = n;

	for(int i = 2; i <= n; i++){
		piramide[l--] = '*';
		piramide[r++] = '*';

		printf("%s\n",piramide);

	}

	free(piramide);
	return 0;
}
