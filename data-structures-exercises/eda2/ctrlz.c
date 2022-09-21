#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha
{
    struct pilha *prox;
    char str[110];

}pilha;

int main()
{
    pilha Editor = malloc(sizeof(pilha));
    Editor->prox = NULL;




    return 0;
}
