#include <stdio.h>
#include <stdlib.h>


typedef struct GuardaPosNota
{
    int pos,quantidade;

} GuardaPosNota;

int main()
{
    int n =0;
    int *notas = malloc(sizeof(int)*101);

    GuardaPosNota x;
    x.pos=-1;
    x.quantidade=-1;
    scanf("%d",&n);
    for(int i=0; i<101; i++)
        notas[i] = 0;

    for(int i=0; i<n; i++)
    {
        int val=0;
        scanf("%d",&val);
        //printf("%d modulo %d = %d\n",val,101,val%101);
        val = val%101;
        notas[val]+=1;

    }
    for(int  i = 0; i<101; i++)
    {
        if( notas[i] >= x.quantidade)
        {
            x.quantidade = notas[i];
            x.pos = i;
        }
    }

	//for(int i = 0;i<101;i++) printf("%d alunos tiraram %d\n",notas[i],i);

    printf("%d\n",x.pos);
    free(notas);
    return 0;
}

///10 20 25 85 40 25 90 25 40 55 40
