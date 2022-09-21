#include <stdio.h>
#include <stdlib.h>
#define N 1000

typedef struct Pilha
{
    struct Pilha *prox;
    int valor;

} Pilha;

Pilha *criaPilha()
{
    Pilha *p = malloc(sizeof(Pilha));
    p->prox = NULL;
    p->valor = -1;
    return p;

}

void empilha(Pilha *p,int n)
{
    Pilha *novo = malloc(sizeof(Pilha));
    novo->prox = p->prox;
    p->prox = novo;
    novo->valor = n;
}

void desempilhaPrinta(Pilha *p)
{
    Pilha *lixo = malloc(sizeof(Pilha));
    printf("%d\n",p->prox->valor);
    lixo->prox = p->prox->prox;
    p->prox = lixo->prox;
    free(lixo);

}

int main()
{
    unsigned int *v = malloc(N*sizeof(unsigned int));
    int i=0, soma =0,limsoma=0;
    while(1)
    {
        scanf("%d",&v[i]);
        if(v[i] == 0 ) break;
        i++;
    }
    scanf("%d",&limsoma);
    Pilha *p = criaPilha();
    for(int j=0;j<i;j++)
    {

        soma+=v[j];
        if(soma>limsoma)
        {
           // printf("OI");
            empilha(p,v[j]);
            soma = 0;
        }
    }

    while(p->prox!=NULL)
    {
        desempilhaPrinta(p);
    }
    free(p);
    free(v);
    return 0;
}
