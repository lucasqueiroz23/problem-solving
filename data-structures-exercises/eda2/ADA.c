#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct caracteres
{
    char caracter;
    int qtdOcorrencias,primeiraOcorrencia;

};

void merge(struct caracteres *v, int l, int m, int r)
{
    struct caracteres *v2 = malloc(sizeof(struct caracteres)*(r-l+1));
    int k=0;
    int i = l;
    int j = m+1;
    while(i<=m && j<=r)
    {
        if(v[i].qtdOcorrencias<v[j].qtdOcorrencias)
        {
            v2[k].qtdOcorrencias = v[i].qtdOcorrencias;
            v2[k].primeiraOcorrencia = v[i].primeiraOcorrencia;
            v2[k].caracter = v[i].caracter;
            i++;
            k++;
        }
        else
        {
            v2[k].qtdOcorrencias = v[j].qtdOcorrencias;
            v2[k].primeiraOcorrencia = v[j].primeiraOcorrencia;
            v2[k].caracter = v[j].caracter;
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        v2[k].qtdOcorrencias = v[i].qtdOcorrencias;
        v2[k].primeiraOcorrencia = v[i].primeiraOcorrencia;
        v2[k].caracter = v[i].caracter;
        i++;
        k++;
    }
    while(j<=r)
    {
        v2[k].qtdOcorrencias = v[j].qtdOcorrencias;
        v2[k].primeiraOcorrencia = v[j].primeiraOcorrencia;
        v2[k].caracter = v[j].caracter;
        k++;
        j++;
    }
    k=0;
    for(i = l; i<=r; i++)
    {
        v[i].qtdOcorrencias = v2[k].qtdOcorrencias;
        v[i].caracter = v2[k].caracter;
        v[i].primeiraOcorrencia = v2[k].primeiraOcorrencia;
        k++;
    }


    free(v2);

}

void mergeSort(struct caracteres *v, int l, int r)
{
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSort(v,l,m);
    mergeSort(v,m+1,r);
    merge(v,l,m,r);

}


int main()
{

    char string[100000];
    scanf("%s",string);
    int tamString = strlen(string);
    struct caracteres *vetorCaracteres = malloc(tamString*sizeof(struct caracteres));

    int j=0;
    int i=0;
    vetorCaracteres[0].caracter = string[0];
    vetorCaracteres[0].primeiraOcorrencia = 0;
    vetorCaracteres[0].qtdOcorrencias = 1;

    int quantidadeDeStructs = 1;

    for(i = 1; i<tamString; i++)
    {
        if(string[i] == string[i-1])
        {
            vetorCaracteres[j].qtdOcorrencias++;

        }
        else
        {
            j++;
            vetorCaracteres[j].caracter = string[i];
            vetorCaracteres[j].primeiraOcorrencia = i;
            vetorCaracteres[j].qtdOcorrencias = 1;
            quantidadeDeStructs++;
        }

    }


    mergeSort(vetorCaracteres,0,quantidadeDeStructs-1);


    for(j = quantidadeDeStructs-1; j>=0; j--)
    {
        printf("%d %c %d",vetorCaracteres[j].qtdOcorrencias,vetorCaracteres[j].caracter,vetorCaracteres[j].primeiraOcorrencia);
        printf("\n");
    }


    free(vetorCaracteres);
    return 0;
}
