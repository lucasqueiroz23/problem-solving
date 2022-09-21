#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha
{
    struct pilha *prox;
    char entrada[110];

}Pilha;

Pilha *criaPilha()
{
    Pilha *novaPilha = malloc(sizeof(Pilha));
    novaPilha->prox = NULL;
    return novaPilha;
}

void empilha(Pilha *p, char *str)
{
    Pilha *novo = malloc(sizeof(Pilha));
    strcpy(novo->entrada,str);
    novo->prox = p->prox;
   // printf("empilhado: %s\n",novo->entrada);
    p->prox = novo;

}

void desfaz(Pilha *p)
{
    if(p->prox==NULL)
    {
        printf("NULL\n");
        return;
    }
    Pilha *lixo = malloc(sizeof(Pilha));
    printf("%s\n",p->prox->entrada);
    lixo->prox=p->prox->prox;
    p->prox = lixo->prox;
    free(lixo);
}

int main()
{
    Pilha *p = criaPilha();
    char cmd[120];
    char str[120];
    while(scanf("%[^\n]%*c",cmd)!=EOF)
    {

        if(cmd[0] == 'd')
        {
            desfaz(p);
            continue;
        }
        strncpy(str,cmd+8,strlen(cmd));
        //printf("%s\n",str);
        empilha(p,cmd+8);

    }



    return 0;
}
