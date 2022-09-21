#include <stdio.h>
#include <stdlib.h>


typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    int **matrizAdjacencia;

} graph;

typedef struct aresta
{
    int vertice1;
    int vertice2;

} aresta;

aresta inicializaAresta(int v1,int v2)
{
    aresta a;

    a.vertice1 = v1;
    a.vertice2 = v2;

    return a;
}

int **MATRIXInit(int qtdLinhas,int qtdColunas,int valorDeInicializacao)
{

    int **matrix = malloc(qtdLinhas*sizeof(int*));

    for(int i = 0; i<qtdLinhas; i++)
        matrix[i] = malloc(qtdColunas*sizeof(int));

    for(int i = 0; i<qtdLinhas; i++)
        for(int j = 0; j<qtdColunas; j++)
        {
            matrix[i][j] = valorDeInicializacao;
            //if(i == j) matrix[i][j]++;
        }
    return matrix;
}

graph *graphInit(int qtdVertices)
{
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->matrizAdjacencia = MATRIXInit(qtdVertices,qtdVertices,0);

    return g;
}

void insereAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    if(g->matrizAdjacencia[v1][v2] == 0) g->quantidadeArestas++;

    g->matrizAdjacencia[v1][v2] = 1;
    g->matrizAdjacencia[v2][v1] = 1;

}

void removeAresta(graph *g, aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    if(g->matrizAdjacencia[v1][v2] == 1) g->quantidadeArestas--;

    g->matrizAdjacencia[v1][v2] = 0;
    g->matrizAdjacencia[v2][v1] = 0;

}

int devolveQuantidadeArestas(aresta a[],graph *g)
{
    int v1,v2, quantidadeArestas = 0;
    for(v1 = 0; v1 < g->quantidadeVertices; v1++)
        for(v2 = v1+1; v2<g->quantidadeVertices; v2++)
            if(g->matrizAdjacencia[v1][v2] == 1)
                a[quantidadeArestas++] = inicializaAresta(v1,v2);

    return quantidadeArestas;
}

void printaMatriz(graph *g, int v)
{
	for(int i = 0; i<v; i++)
    {
        for(int j = 0; j<v; j++)
            printf("%d ",g->matrizAdjacencia[i][j]);
        printf("\n");
    }
	printf("\n");


}

int *verticesJaVisitados;
int *verticesDoGrafo;

int *iniciaVetor_verticesJaVisitados(int qtdVertices)
{
    int *vetor = malloc(qtdVertices*sizeof(int));
    for(int i = 0; i<qtdVertices; i++)
        vetor[i] = 0;
    return vetor;
}

int quantidadeDeVerticesNaComponenteConexa;
int quantidadeDeVerticesNaMAIORComponenteConexa = 0;

typedef struct guardaComponentesConexas{

	int primeiroVerticeDaComponenteConexa;
	int quantidadeDeConexoes;

} guardaComponentesConexas;

void DFS_buscaEmProfundidade_RECURSIVA(graph *g, aresta a, int posicaoNasComponentesConexas)
{
    int v2 = a.vertice2;
    verticesJaVisitados[v2] = 1;
    verticesDoGrafo[v2] = posicaoNasComponentesConexas;
	quantidadeDeVerticesNaComponenteConexa++;


    for(int v1 = 0; v1 < g->quantidadeVertices ; v1++)
        if(g->matrizAdjacencia[v2][v1] != 0)
            if(verticesJaVisitados[v1] == 0)
            {
				aresta novaAresta;
				novaAresta.vertice1 = v2;
				novaAresta.vertice2 = v1;
                DFS_buscaEmProfundidade_RECURSIVA(g, novaAresta,posicaoNasComponentesConexas);
            }
}

int devolveQuantidadeDeComponentesConexos(graph *g, guardaComponentesConexas *compConexas)
{
	int qtdConexos = 0;


	verticesJaVisitados = iniciaVetor_verticesJaVisitados(g->quantidadeVertices);
	verticesDoGrafo = iniciaVetor_verticesJaVisitados(g->quantidadeVertices);

	for(int indiceDeVertices = 0; indiceDeVertices < g->quantidadeVertices; indiceDeVertices++)
	{
		if(verticesJaVisitados[indiceDeVertices] == 0)
		{
			quantidadeDeVerticesNaComponenteConexa = 0;

			aresta novaAresta;
			novaAresta.vertice1 = indiceDeVertices;
			novaAresta.vertice2 = indiceDeVertices;



			DFS_buscaEmProfundidade_RECURSIVA(g,novaAresta,qtdConexos);

			if(quantidadeDeVerticesNaComponenteConexa > quantidadeDeVerticesNaMAIORComponenteConexa )
				quantidadeDeVerticesNaMAIORComponenteConexa  = quantidadeDeVerticesNaComponenteConexa;

			compConexas[qtdConexos].primeiroVerticeDaComponenteConexa = indiceDeVertices;
			compConexas[qtdConexos].quantidadeDeConexoes = quantidadeDeVerticesNaComponenteConexa;

			qtdConexos++;

		}
	}


	return qtdConexos;
}


int main()
{
    int v = 0;
    int cidadeEmQueJoaoEsta = 0;
    scanf("%d%d",&v,&cidadeEmQueJoaoEsta);

    graph *g = graphInit(v);
    int v1=0,v2=0;
    while(scanf("%d %d",&v1,&v2)!= EOF)
    {
        aresta a = inicializaAresta(v1,v2);
        insereAresta(g,a);

    }

	guardaComponentesConexas *compConexas = malloc(g->quantidadeVertices*sizeof(guardaComponentesConexas));

	int quantidadeDeConexos = devolveQuantidadeDeComponentesConexos(g,compConexas);

	if(compConexas[verticesDoGrafo[cidadeEmQueJoaoEsta]].quantidadeDeConexoes == quantidadeDeVerticesNaMAIORComponenteConexa )
	{
		if(quantidadeDeVerticesNaMAIORComponenteConexa  == 1) printf("Fique em casa\n");
		else printf("Bora pra estrada\n");
	}
	else
	{
		for(int i = 0;i<quantidadeDeConexos;i++)
		{
			if(compConexas[i].quantidadeDeConexoes == quantidadeDeVerticesNaMAIORComponenteConexa )
			{
				printf("Vamos para %d\n",compConexas[i].primeiroVerticeDaComponenteConexa);
				break;
			}

		}

	}



	free(compConexas);
	free(verticesDoGrafo);
	free(verticesJaVisitados);
    return 0;
}

