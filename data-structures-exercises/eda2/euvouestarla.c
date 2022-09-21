#include <stdio.h>
#include <stdlib.h>

int **MATRIXInit(int qtdLinhas,int qtdColunas,int valorDeInicializacao)
{

    int **matrix = malloc(qtdLinhas*sizeof(int*));

    for(int i = 0; i<qtdLinhas; i++)
        matrix[i] = malloc(qtdColunas*sizeof(int));

    for(int i = 0; i<qtdLinhas; i++)
        for(int j = 0; j<qtdColunas; j++)
            if(i == j)
            {
                matrix[i][j] = valorDeInicializacao;
                matrix[i][j]++;
            }
            else
                matrix[i][j] = valorDeInicializacao;

    return matrix;
}

void printaMatrizQuadrada(int **m, int tam)
{
    for(int i = 0; i<tam; i++)
    {
        printf("\n");
        for(int j = 0; j<tam; j++)
            printf("%d ",m[i][j]);
    }

}

void conectaVertices(int **m, int vertice,int quantidadeVerticesAConectar)
{
    int pos=0;
    while(quantidadeVerticesAConectar>0)
    {
        scanf("%d",&pos);
        if(m[pos][vertice]!= 1)
        {
            m[pos][vertice]++;
            m[vertice][pos]++;
        }
        quantidadeVerticesAConectar--;
    }

}

void indicaLocaisEmQueJulianoEsteve(int **m, int pos, int tam)
{
	for(int i = 0;i<tam;i++)
	{
		if(m[pos][i] == 1)
		{
			m[i][pos] = 2;
			m[pos][i] = 2;
			m[i][i] = 2;
			m[pos][pos]= 2;

		}
	}

}

int main()
{
    int n = 0, m = 0, j = 0;
    scanf("%d %d %d",&n,&m,&j);
    int **matriz = MATRIXInit(n,n,0);
    int contaAteN = 0;

    while(contaAteN<n)
    {
        int a = 0;
        scanf("%d",&a);
        conectaVertices(matriz,contaAteN,a);

        contaAteN++;
    }
    while(m>0)
    {
        int pos=0;
        scanf("%d",&pos);
        indicaLocaisEmQueJulianoEsteve(matriz,pos,n);

        m--;
    }
    int contaAteJ = 0;
	while(contaAteJ<j)
	{
		int pos = 0;
		scanf("%d",&pos);
		if(matriz[pos][pos] == 2)
			printf("Eu vou estar la\n");
		else
			printf("Nao vou estar la\n");

		contaAteJ++;
	}

    printaMatrizQuadrada(matriz,n);
    printf("\n");

    free(matriz);
    return 0;
}
