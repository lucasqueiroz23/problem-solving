#include<stdio.h>
#include <stdlib.h>

void ordenaPorInsercao(int *v, int n)
{
    int tmp=0;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            tmp=v[i];
            v[i]=v[i+1];
            v[i+1]=tmp;

        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j = i+1;j>0;j--)
        {
            if(v[j]<v[j-1])
            {
                tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            } else break;
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
    int v[50000];
    int j=0,k=0;

    for(j=0;j<50000;j++)
    {
        if(scanf("%d",&v[j]) == EOF) break;

    }
    ordenaPorInsercao(v,j);
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

