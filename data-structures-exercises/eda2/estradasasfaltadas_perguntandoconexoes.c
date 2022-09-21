
#include <stdio.h>
#include <stdlib.h>


typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    int **matrizAdjacencia;
    int **fechoTransitivo;

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

void insereAresta(graph *g,aresta a, int bool_v2parav1)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    if(g->matrizAdjacencia[v1][v2] == 0) g->quantidadeArestas++;

    g->matrizAdjacencia[v1][v2] = 1;

    if(bool_v2parav1 == 2) g->matrizAdjacencia[v2][v1] = 1;

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

void printaMatriz(int **matriz, int v)
{
	for(int i = 0; i<v; i++)
    {
        for(int j = 0; j<v; j++)
            printf("%d ",matriz[i][j]);
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

void FloydWarshall(graph *g)
{
	int i,s,t;
	g->fechoTransitivo = MATRIXInit(g->quantidadeVertices,g->quantidadeVertices,0);
	for(s = 0; s<g->quantidadeVertices;s++)
		for(t = 0; t< g->quantidadeVertices;t++)
			g->fechoTransitivo[s][t] = g->matrizAdjacencia[s][t];

	for(s = 0; s<g->quantidadeVertices;s++) g->fechoTransitivo[s][s] = 1;

	for(i = 0; i<g->quantidadeVertices;i++)
		for(s = 0;s<g->quantidadeVertices;s++)
			if(g->fechoTransitivo[s][i] == 1)
				for(t = 0; t< g->quantidadeVertices; t++)
					if(g->fechoTransitivo[i][t] == 1)
						g->fechoTransitivo[s][t] = 1;

}

void devolveAlcancabilidade(graph *g, int v1, int v2)
{
	if(g->fechoTransitivo[v1][v2] == g->fechoTransitivo[v2][v1] && g->fechoTransitivo[v1][v2] == 1)
	{
		printf("Ida e Volta\n");
		return;
	}

	if(g->fechoTransitivo[v1][v2] != g->fechoTransitivo[v2][v1] && g->fechoTransitivo[v1][v2] == 1)
	{
		printf("Apenas Ida\n");
		return;
	}

	if(g->fechoTransitivo[v1][v2] != g->fechoTransitivo[v2][v1] && g->fechoTransitivo[v2][v1] == 1)
	{
		printf("Apenas Volta\n");
		return;
	}

	if(g->fechoTransitivo[v1][v2] == g->fechoTransitivo[v2][v1] && g->fechoTransitivo[v1][v2] == 0)
	{
		printf("Impossibru\n");
		return;
	}



}


int main()
{
    int v = 0;
    scanf("%d",&v);
    graph *g = graphInit(v);
    int v1=0,v2=0,d=0;
    while(scanf("%d %d %d",&v1,&v2,&d)!= EOF)
    {
		if(v1 == v2 && v2 == d && d ==0) break;

        aresta a = inicializaAresta(v1,v2);
        insereAresta(g,a,d);

    }

	FloydWarshall(g);
	int t=0, x=0;
	while(scanf("%d%d",&t,&x)!=EOF)
	{
		devolveAlcancabilidade(g,t,x);

	}

	/*
	printf("\n\n");
	printaMatriz(g->fechoTransitivo,v);

	printf("\n\n");

	printaMatriz(g->matrizAdjacencia,v);

*/

	return 0;
}
