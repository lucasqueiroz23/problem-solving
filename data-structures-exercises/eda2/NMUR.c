#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int valor;
    struct pilha *prox;

} pilha;

void insertionSort(int *v, int l, int r)
{
    int tmp=0;
    for(int i=l; i<r; i++)
    {

        if(v[i]>v[i+1])
        {
            tmp=v[i];
            v[i]=v[i+1];
            v[i+1]=tmp;

        }
    }
    for(int i=l; i<r; i++)
    {
        for(int j = i+1; j>l; j--)
        {
            if(v[j]<v[j-1])
            {
                tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
            else break;
        }
    }

}

int separa(int *v,int l, int r)
{

    int c = v[r];
    int j = l;
    for(int k = l; k< r ; k++)
        if(v[k]<=c)
        {

            int tmp = v[k];
            v[k] = v[j];
            v[j] = tmp;
            j++;

        }

    int tmp = v[j];
    v[j] = v[r];
    v[r] = tmp;


    return j;


}

void quickSort(int *v, int l, int r)
{

    if(r-l<=32)
    {
        insertionSort(v,l,r);
        return;

    }
    int m = (l+r)/2;

    int t = v[m];
    v[m] = v[r-1];
    v[r-1] = t;

    if(v[l]>v[r-1])
    {
        int tmp = v[l];
        v[l] = v[r-1];
        v[r-1] = tmp;
    }
    if(v[r]<v[l])
    {
        int tmp = v[r];
        v[r] = v[l];
        v[l] = tmp;
    }
    if(v[m]<v[r-1])
    {
        int tmp = v[r];
        v[r] = v[r-1];
        v[r-1] = tmp;
    }
    int j = separa(v,l,r);
    quickSort(v,l,j-1);
    quickSort(v,j+1,r);


}

int eliminaOrdena(int *v, int tam)
{
    int i = 0, j = 1, quantidadeDeRepetidos = 0;
    quickSort(v,0,tam-1);
    while(j<tam)
    {
        while(v[i] == v[j])
        {
            v[j] = -1;
            quantidadeDeRepetidos++;
            j++;
        }
        i = j;
        j++;

    }
    quickSort(v,0,tam-1);
    return quantidadeDeRepetidos;

}

void somaAdjacentes(int *v,int l, int r)
{
	int *vaux = malloc(sizeof(int)*)




}

int main()
{
    int n = 0,posFinal1 = 0;
    int *v = malloc(1073741824*sizeof(int));
    scanf("%d",&n);

    int i=0;

    for(i = i; i<n; i++)
        scanf("%d",&v[i]);

    if(n%2!=0)
    {
        v[i] = 1000000000;
        n = i+1;
    }
    i = eliminaOrdena(v,n);
    int j = i+1;



    for(int j = 0; j<n; j++) printf("%d ",v[j]);
    free(v);
    return 0;
}
