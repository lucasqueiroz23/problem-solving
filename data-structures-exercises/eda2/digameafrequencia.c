#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula
{
    int posicao;
    struct celula *prox;

} celula;

typedef struct ED
{
    int posicao,quantidade;

} ED;

void insere(celula *le, int val)
{
    while(le->prox!=NULL) le = le->prox;
    celula *novo = malloc(sizeof(celula));
    novo->prox = NULL;
    le->prox = novo;
    novo->posicao = val;

}

void mergeIguais(ED *v, int l, int m, int r)
{
    ED *v2 = malloc(sizeof(ED)*(r-l+1));
    int k=0;
    int i = l;
    int j = m+1;
    while(i<=m && j<=r)
    {
        if(v[i].posicao<=v[j].posicao)
        {
            v2[k].quantidade = v[i].quantidade;
            v2[k].posicao = v[i].posicao;
            i++;
            k++;
        }
        else
        {
            v2[k].quantidade = v[j].quantidade;
            v2[k].posicao = v[j].posicao;
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        v2[k].quantidade = v[i].quantidade;
        v2[k].posicao = v[i].posicao;
        i++;
        k++;
    }
    while(j<=r)
    {
        v2[k].quantidade = v[j].quantidade;
        v2[k].posicao = v[j].posicao;
        j++;
        k++;
    }
    k=0;
    for(i = l; i<=r; i++)
    {
        v[i].quantidade= v2[k].quantidade;
        v[i].posicao = v2[k].posicao;
        k++;
    }


    free(v2);

}

void mergeSortIguais(ED *v, int l, int r)
{
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSortIguais(v,l,m);
    mergeSortIguais(v,m+1,r);
    mergeIguais(v,l,m,r);

}

void mergeAparicoes(ED *v, int l, int m, int r)
{
    ED *v2 = malloc(sizeof(ED)*(r-l+1));
    int k=0;
    int i = l;
    int j = m+1;
    while(i<=m && j<=r)
    {
        if(v[i].quantidade<=v[j].quantidade)
        {
            v2[k].quantidade = v[i].quantidade;
            v2[k].posicao = v[i].posicao;
            i++;
            k++;
        }
        else
        {
            v2[k].quantidade = v[j].quantidade;
            v2[k].posicao = v[j].posicao;
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        v2[k].quantidade = v[i].quantidade;
        v2[k].posicao = v[i].posicao;
        i++;
        k++;
    }
    while(j<=r)
    {
        v2[k].quantidade = v[j].quantidade;
        v2[k].posicao = v[j].posicao;
        j++;
        k++;
    }
    k=0;
    for(i = l; i<=r; i++)
    {
        v[i].quantidade= v2[k].quantidade;
        v[i].posicao = v2[k].posicao;
        k++;
    }


    free(v2);

}

void mergeSortAparicoes(ED *v, int l, int r)
{
    if(l>=r) return;
    int m = (l+r)/2;
    mergeSortAparicoes(v,l,m);
    mergeSortAparicoes(v,m+1,r);
    mergeAparicoes(v,l,m,r);

}

void ordenaEspecifico( ED *v, int tamVetor)
{
	int j=0;
	for(int i = 0;i<tamVetor;i++)
	{
		if(v[i+1].quantidade!=v[i].quantidade)
		{

			mergeSortIguais(v,j,i);
			j = i+1;

		}

	}
	mergeSortIguais(v,j,tamVetor-1);

}

int main()
{

    int *ht = malloc(128*sizeof(int));
    for(int i = 0; i< 128; i++)
        ht[i] = 0;

    char str[1000];
    while(scanf("%s",str)!=EOF)
    {
        celula *le = malloc(sizeof(celula));
        le->posicao=-1;
        le->prox = NULL;

        unsigned tamString = strlen(str);
        int quantidadeDeCaracteresDiferentes=0;
        for(int i = 0; i<tamString; i++)
        {
            int pos = str[i]%128;
            if(ht[pos] == 0)
            {
                quantidadeDeCaracteresDiferentes++;
                insere(le,pos);

            }
            ht[pos]+=1;

        }

        int *vaux = malloc(sizeof(int)*quantidadeDeCaracteresDiferentes);
        for(int i = 0; i<quantidadeDeCaracteresDiferentes; i++)
        {
            vaux[i] = le->prox->posicao;
            le=le->prox;
        }

        ED *vFinal = malloc(quantidadeDeCaracteresDiferentes*sizeof(ED));
        for(int i = 0; i<quantidadeDeCaracteresDiferentes; i++)
        {

            vFinal[i].posicao = vaux[i];
            vFinal[i].quantidade = ht[vaux[i]];

        }
        mergeSortAparicoes(vFinal,0,quantidadeDeCaracteresDiferentes-1);
		ordenaEspecifico(vFinal,quantidadeDeCaracteresDiferentes);


        for(int i = 0; i<quantidadeDeCaracteresDiferentes; i++)
        {
            printf("%d %d\n",vFinal[i].posicao,vFinal[i].quantidade);
            ht[vFinal[i].posicao] = 0;
        }

        free(vFinal);
        free(vaux);
        free(le);
        printf("\n");
    }

    free(ht);
    return 0;
}
