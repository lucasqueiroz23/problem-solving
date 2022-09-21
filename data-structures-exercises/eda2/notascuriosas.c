#include <stdio.h>
#include <stdlib.h>

typedef struct guardaPosicao
{
    int qtdNotas;
    int pos;

} gp;

int main()
{
    gp *x = malloc(sizeof(gp));
    x->qtdNotas=-1;
    x->pos = -1;

    int *ht = malloc(1001*sizeof(int));

    for(int i = 0; i<1001; i++)
        ht[i] = 0;
    int qtdAlunos = 0;
    while(scanf("%d",&qtdAlunos)!=EOF)
    {
        for(int i = 0; i<qtdAlunos; i++)
        {
            int val=0;
            scanf("%d",&val);
            val = val%1001;
            ht[val]+=1;

        }
    }
    for(int i = 0; i<1001; i++)
    {
        if(ht[i]>=x->qtdNotas)
        {
            x->qtdNotas = ht[i];
            x->pos = i;

        }

    }
    printf("%d\n",x->pos);

    free(x);
    free(ht);
    return 0;
}
