#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// LISTA DE ADJACENCIAS

// "celula" representa cada node de uma lista encadeada
typedef struct celula
{
    int vertice;

    char nome[32];

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


/// funcao remove aresta mal escrita. Reescrever quando tiver tempo para ficar mais legivel.
/// OBS: FUNCAO AINDA NAO TESTADA!
void removeAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    celula *c1 = g->listaDeAdjacencias[v1];
    celula *c2 = g->listaDeAdjacencias[v2];

    while(c1->prox->vertice!= v2 && c1!= NULL)
        c1 = c1->prox;

    if(c1 == NULL) return; ///nao existe conexao

    while(c2->prox->vertice!= v1 )
        c2 = c2->prox;

    celula *novo1 = c1->prox;
    celula *novo2 = c2->prox;

    c1->prox = novo1->prox;
    c2->prox = novo2->prox;

    free(novo1);
    free(novo2);


}

int devolveQuantidadeArestas_E_formaVetorDeArestas(aresta a[],graph *g)
{
    int quantidadeArestas = 0;
    for(int indiceVertices = 0; indiceVertices<g->quantidadeVertices; indiceVertices++)
        for(celula *indiceCelulas = g->listaDeAdjacencias[indiceVertices] ; indiceCelulas!=NULL ; indiceCelulas = indiceCelulas->prox)
            if(indiceVertices < indiceCelulas -> vertice) a[quantidadeArestas++] = inicializaAresta(indiceVertices,indiceCelulas->vertice);

    return quantidadeArestas;
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
    int c=0,r=0;
    while(1)
    {
        scanf("%d%d",&c,&r);
        if(c == r && r == 0) break;
        graph *g = graphInit(c);

		for(int i = 0;i<c;i++)
			scanf("%s",g->listaDeAdjacencias[i]->nome);
		for(int i = 0;i<r;i++)
		{
			char r1[32];
			char r2[32];
			scanf("%s %s",r1,r2);
			int j = 0;
			while(g->listaDeAdjacencias[j]->nome!=r1) j++;

			int k = 0;
			while(g->listaDeAdjacencias[k]->nome!=r2) k++;

			aresta a;
			a.vertice1 = j;
			a.vertice2 = k;

			insereAresta(g,a);


		}


    }



    return 0;
}
