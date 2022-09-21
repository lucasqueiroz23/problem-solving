#include <stdlib.h>
#include <stdio.h>

/* LISTA DE ADJACENCIAS*/

int infinity = 2147483647;

/* "celula" representa cada node de uma lista encadeada*/
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

aresta inicializaAresta(int v1,int v2, int pesoDaAresta)
{
    aresta a;

    a.vertice1 = v1;
    a.vertice2 = v2;
	a.peso = pesoDaAresta;


    return a;
}

celula *criaNoCabeca(int valorDoVertice)
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = valorDoVertice;
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
    int i;
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->listaDeAdjacencias = malloc(qtdVertices*sizeof(celula));

    for(i = 0; i< qtdVertices; i++)
        g->listaDeAdjacencias[i] = criaNoCabeca(i);

    return g;
}

void insereAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;
    criaAdjacencia(v2, g->listaDeAdjacencias[v1]);
    criaAdjacencia(v1, g->listaDeAdjacencias[v2]);

}

/* GRAFOS DIRIGIDOS (DIGRAPHS)*/

void insereAresta_DIRECAO_UNICA(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    criaAdjacencia(v2, g->listaDeAdjacencias[v1]);

}

void GRAPHcptD1(graph *graph, int s) {

  int mature[1000]; /*MAX_VERTICES*/
  int v;
  int *distances = malloc(graph->quantidadeVertices * sizeof(int));
  int *parent = malloc(graph->quantidadeVertices * sizeof(int));

  for(v = 0; v < graph->quantidadeVertices; v++) {
    parent[v] = -1;
    distances[v] = infinity;
    mature[v] = 0;
  }

  parent[s] = s;
  distances[s] = 0;
  int z, i;
  celula *t;

  while(1) {
    int min = infinity, y;

    for(z = 0; z < graph->quantidadeVertices; z++) {
      if(mature[z]) continue;
      if(distances[z] < min) {
        min = distances[z];
        y = z;
      }
    }
    if(min == infinity) break;

    for(t = graph->listaDeAdjacencias[y]->prox; t != NULL; t = t->prox) {
      printf("\t\t%d\n",distances[y]);
      if(mature[t->vertice]) continue;
      if(distances[y] + t->peso < distances[t->vertice]) {
        distances[t->vertice] = distances[y] + t->peso;
        parent[t->vertice] = y;
      }
    }
    mature[y] = 1;
  }

  for(i = 0; i < graph->quantidadeVertices; i++) {
        printf("parent[%d]:%d\n", i, parent[i]);
    }
  for(i = 0; i < graph->quantidadeVertices; i++) {
        printf("distances[%d]:%d\n", i, distances[i]);
    }
  for(i = 0; i < graph->quantidadeVertices; i++) {
        printf("mature[%d]:%d\n", i, mature[i]);
    }
}

int main() {
    int qtdVertices, qtdArestas, i;
    scanf("%d%d", &qtdVertices, &qtdArestas);

    qtdVertices += 2;

    graph *g = graphInit(qtdVertices);

    int v1, v2, peso;
    for(i = 0; i < qtdArestas; i ++) {
        scanf("%d%d%d", &v1, &v2, &peso);
        aresta a = inicializaAresta(v1, v2, peso);
        insereAresta(g, a);
    }

    GRAPHcptD1(g, 0);

    return 0;
}
