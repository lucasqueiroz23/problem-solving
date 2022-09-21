#include <stdlib.h>
#include <stdio.h>

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
	criaAdjacencia(v1, g->listaDeAdjacencias[v2]);

}

int *inicializaVetor(int tamanhoDoVetor)
{
	int *vetor = malloc(tamanhoDoVetor*sizeof(int));
	for(int i = 0; i< tamanhoDoVetor; i++)
		vetor[i] = 0;
	return vetor;
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

    for(celula *indiceVertices = g->listaDeAdjacencias[v2]->prox; indiceVertices!=NULL; indiceVertices = indiceVertices->prox)
    {
        int v1 = indiceVertices->vertice;
        if(verticesJaVisitados[v1] == 0)
        {
            aresta novaAresta;
            novaAresta.vertice1 = v2;
            novaAresta.vertice2 = v1;
            DFS_buscaEmProfundidade_RECURSIVA(g, novaAresta);
        }
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
			if(qtdConexos>1) return qtdConexos;
        }
    }

    return qtdConexos;
}


int main()
{
	int qtdEstacoes=0, qtdConexoes=0;

	scanf("%d%d",&qtdEstacoes,&qtdConexoes);
	int n = 1;

	while(1)
	{
		if(qtdEstacoes == qtdConexoes && qtdEstacoes == 0) break;


		graph *g = graphInit(qtdEstacoes);

		while(qtdConexoes>0)
		{
			int v1=0,v2=0;
			scanf("%d%d",&v1,&v2);
			v1--;
			v2--;
			aresta a = inicializaAresta(v1,v2);
			insereAresta(g,a);

			qtdConexoes--;
		}

		printf("Teste %d\n",n);
		int qtdComponentesConexos = devolveQuantidadeDeComponentesConexos(g);
		if(qtdComponentesConexos>1) printf("falha");
		else printf("normal");

		printf("\n");
		free(g);
		scanf("%d%d",&qtdEstacoes,&qtdConexoes);
		n++;
	}



	return 0;
}

