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

int *iniciaVetor_verticesJaVisitados(int qtdVertices)
{
    int *vetor = malloc(qtdVertices*sizeof(int));
    for(int i = 0; i<qtdVertices; i++)
        vetor[i] = 0;
    return vetor;
}

void DFS_buscaEmProfundidade_RECURSIVA(graph *g, aresta a)
{
    int v2 = a.vertice2;
    verticesJaVisitados[v2] = 1;



    for(int v1 = 0; v1 < g->quantidadeVertices ; v1++)
        if(g->matrizAdjacencia[v2][v1] != 0)
            if(verticesJaVisitados[v1] == 0)
            {
				aresta novaAresta;
				novaAresta.vertice1 = v2;
				novaAresta.vertice2 = v1;
                DFS_buscaEmProfundidade_RECURSIVA(g, novaAresta);
            }
}

int devolveQuantidadeDeComponentesConexos(graph *g)
{
	int qtdConexos = 0;

	verticesJaVisitados = iniciaVetor_verticesJaVisitados(g->quantidadeVertices);

	for(int indiceDeVertices = 0; indiceDeVertices < g->quantidadeVertices; indiceDeVertices++)
	{
		if(verticesJaVisitados[indiceDeVertices] == 0)
		{
			aresta novaAresta;
			novaAresta.vertice1 = indiceDeVertices;
			novaAresta.vertice2 = indiceDeVertices;



			DFS_buscaEmProfundidade_RECURSIVA(g,novaAresta);
			qtdConexos++;

		}
	}

	return qtdConexos;
}

int main()
{
    int v = 0;
    scanf("%d",&v);
    graph *g = graphInit(v);
    int v1=0,v2=0;
    while(scanf("%d %d",&v1,&v2)!= EOF)
    {
        aresta a = inicializaAresta(v1,v2);
        insereAresta(g,a);

    }

	int quantidadeDeConexos = devolveQuantidadeDeComponentesConexos(g);
	printf("%d\n",quantidadeDeConexos);





    return 0;
}
