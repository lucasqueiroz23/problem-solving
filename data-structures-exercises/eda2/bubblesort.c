#include<stdio.h>
#include <stdlib.h>

void ordenacaoDaBolha(int *v, int n)
{
    int tmp =0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
           if(v[j+1] < v[j])
           {
             tmp = v[j];
             v[j] = v[j+1];
             v[j+1] = tmp;
           }
        }
    }
}

void printaVetor(int *v, int tam)
{
    for(int i=0;i< tam;i++)
    {
        if(i+1 == tam)
        {
            printf("%d ",v[i]);
            break;
        }
        printf("%d ",v[i]);
    }
}


int main()
{
    int v[1000];
    int j=0,k=0;

    for(j=0;j<1000;j++)
    {
        if(scanf("%d",&v[j]) == EOF) break;

    }
    ordenacaoDaBolha(v,j);
    printaVetor(v,j);

    return 0;
}
/*5656
2
78
9
21
2
5
6
8
9
4
7
12
1
1
5
8
1245
9853
8879
218*/
