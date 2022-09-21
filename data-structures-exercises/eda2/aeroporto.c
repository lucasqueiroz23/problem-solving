#include <stdlib.h>
#include <stdio.h>

#define INT_MAX 2147483647
/// LISTA DE ADJACENCIAS

// "celula" representa cada node de uma lista encadeada
typedef struct celula
{
    int vertice;
    int peso;
    struct celula *prox;
} celula;

typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    celula **listaDeAdjacencias;

} graph;

typedef struct aresta
{
    int vertice1;
    int vertice2;
    int peso;

} aresta;

aresta inicializaAresta(int v1,int v2)
{
    aresta a;

    a.vertice1 = v1;
    a.vertice2 = v2;



    return a;
}

celula *criaNoCabeca()
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = -1;
    novaCelula->prox = NULL;

    return novaCelula;
}

void criaAdjacencia(int valorDoVertice, celula *noCabeca)
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = valorDoVertice;
    novaCelula->prox = noCabeca->prox;
    noCabeca->prox = novaCelula;
}

graph *graphInit(int qtdVertices)
{
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->listaDeAdjacencias = malloc(qtdVertices*sizeof(celula));

    for(int i = 0; i< qtdVertices; i++)
        g->listaDeAdjacencias[i] = criaNoCabeca();

    return g;
}

void insereAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;
    criaAdjacencia(v2, g->listaDeAdjacencias[v1]);


}

int *inicializaVetor(int tamanhoDoVetor)
{
	int *vetor = malloc(tamanhoDoVetor*sizeof(int));
	for(int i = 0; i< tamanhoDoVetor; i++)
		vetor[i] = 0;
	return vetor;
}

int maiorQuantidadeDeConexoes;

int main()
{
	int qtdAeroportos=0, qtdVoos=0;

	scanf("%d%d",&qtdAeroportos,&qtdVoos);
	int n = 1;

	while(1)
	{
		if(qtdAeroportos == qtdVoos && qtdAeroportos == 0) break;

		printf("Teste %d\n",n);
		graph *g = graphInit(qtdAeroportos);
		int *ht = inicializaVetor(qtdAeroportos);
		maiorQuantidadeDeConexoes = 0;

		while(qtdVoos>0)
		{
			int v1=0,v2=0;
			scanf("%d%d",&v1,&v2);
			v1--;
			v2--;
			aresta a = inicializaAresta(v1,v2);
			insereAresta(g,a);
			ht[v1]++;
			ht[v2]++;
			if(ht[v1]>maiorQuantidadeDeConexoes)
				maiorQuantidadeDeConexoes = ht[v1];
			if(ht[v2]>maiorQuantidadeDeConexoes)
				maiorQuantidadeDeConexoes = ht[v2];


			qtdVoos--;
		}

		for(int i = 0;i<qtdAeroportos;i++)
			if(ht[i] == maiorQuantidadeDeConexoes)
			{
				int val = i + 1;
				printf("%d ",val);
			}


		printf("\n");
		free(g);
		free(ht);
		scanf("%d%d",&qtdAeroportos,&qtdVoos);
		n++;
	}



	return 0;
}
