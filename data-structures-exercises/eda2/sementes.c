#include <stdio.h>
#include <stdlib.h>

typedef struct guardaNumeros
{
    int nota;
	unsigned long int codigo;

} guardaNumeros;

void insertionSortPorNota(guardaNumeros *v, int l, int r)
{
    int tmp = 0;
    unsigned long int tmp2 = 0;
    for(int i=l; i<r; i++)
    {

        if(v[i].nota  >  v[i+1].nota)
        {
            tmp = v[i].nota;
            v[i].nota = v[i+1].nota;
            v[i+1].nota = tmp;

            tmp2 = v[i].codigo;
            v[i].codigo = v[i+1].codigo;
            v[i+1].codigo = tmp2;


        }

    }
    for(int i=l; i<r; i++)
    {
        for(int j = i+1; j>l; j--)
        {
            if(v[j].nota < v[j-1].nota)
            {
                tmp = v[j-1].nota;
                v[j-1].nota = v[j].nota;
                v[j].nota = tmp;

                tmp2 = v[j-1].codigo;
                v[j-1].codigo = v[j].codigo;
                v[j].codigo = tmp2;

            }
            else break;
        }
    }

}

int separaPorNota(guardaNumeros *v,int l, int r)
{

    int c = v[r].nota;
    int j = l;
    for(int k = l; k< r ; k++)
        if(v[k].nota <= c)
        {

                int tmp = v[k].nota;
                v[k].nota = v[j].nota;
                v[j].nota = tmp;

                unsigned long int tmp2 = v[k].codigo;
                v[k].codigo = v[j].codigo;
                v[j].codigo = tmp2;

                j++;


        }

    int tmp = v[j].nota;
    v[j].nota = v[r].nota;
    v[r].nota = tmp;

    unsigned long int tmp2 = v[j].codigo;
    v[j].codigo = v[r].codigo;
    v[r].codigo = tmp2;

    return j;


}

void quickSortNota(guardaNumeros *v, int l, int r)
{

    if(r-l<=32)
    {
        insertionSortPorNota(v,l,r);
        return;

    }
    int m = (l+r)/2;

    int t = v[m].nota;
    unsigned long int k = v[m].codigo;

    v[m].nota = v[r-1].nota;
    v[m].codigo = v[r-1].codigo;

    v[r-1].nota = t;
    v[r-1].codigo = k;

    if(v[l].nota > v[r-1].nota)
    {
        int tmp = v[l].nota;
        v[l].nota = v[r-1].nota;
        v[r-1].nota = tmp;

        unsigned long int tmp2 = v[l].codigo;
        v[l].codigo = v[r-1].codigo;
        v[r-1].codigo = tmp2;

    }
    if(v[r].nota < v[l].nota)
    {
        int tmp = v[r].nota;
        v[r].nota = v[l].nota;
        v[l].nota = tmp;

        unsigned long int tmp2 = v[r].codigo;
        v[r].codigo = v[l].codigo;
        v[r].codigo = tmp2;

    }
    if(v[m].nota < v[r-1].nota)
    {
        int tmp = v[r].nota;
        v[r].nota = v[r-1].nota;
        v[r-1].nota = tmp;

        unsigned long int tmp2 = v[r].codigo;
        v[r].codigo = v[r-1].codigo;
        v[r-1].codigo = tmp2;

    }
    int j = separaPorNota(v,l,r);
    quickSortNota(v,l,j-1);
    quickSortNota(v,j+1,r);


}
///////////////////////////////////////
/////////////////////////////////////
///////////////////////////////////
/////////////////////////////////

void insertionSortPorCodigo(guardaNumeros *v, int l, int r)
{
    int tmp = 0;
    unsigned long int tmp2 = 0;
    for(int i=l; i<r; i++)
    {

        if(v[i].codigo  >  v[i+1].codigo)
        {
            tmp = v[i].nota;
            v[i].nota = v[i+1].nota;
            v[i+1].nota = tmp;

            tmp2 = v[i].codigo;
            v[i].codigo = v[i+1].codigo;
            v[i+1].codigo = tmp2;


        }

    }

    for(int i=l; i<r; i++)
    {
        for(int j = i+1; j>l; j--)
        {
            if(v[j].codigo < v[j-1].codigo)
            {
                tmp = v[j-1].nota;
                v[j-1].nota = v[j].nota;
                v[j].nota = tmp;

                tmp2 = v[j-1].codigo;
                v[j-1].codigo = v[j].codigo;
                v[j].codigo = tmp2;

            }
            else break;
        }
    }

}

int separaPorCodigo(guardaNumeros *v,int l, int r)
{

    int c = v[r].codigo;
    int j = l;
    for(int k = l; k< r ; k++)
        if(v[k].codigo <= c)
        {


                int tmp = v[k].nota;
                v[k].nota = v[j].nota;
                v[j].nota = tmp;

                unsigned long int tmp2 = v[k].codigo;
                v[k].codigo = v[j].codigo;
                v[j].codigo = tmp2;

                j++;


        }

    int tmp = v[j].nota;
    v[j].nota = v[r].nota;
    v[r].nota = tmp;

    unsigned long int tmp2 = v[j].codigo;
    v[j].codigo = v[r].codigo;
    v[r].codigo = tmp2;

    return j;


}

void quickSortCodigo(guardaNumeros *v, int l, int r)
{

    if(r-l<=32)
    {
        insertionSortPorCodigo(v,l,r);
        return;

    }
    int m = (l+r)/2;

    int t = v[m].nota;
    unsigned long int k = v[m].codigo;

    v[m].nota = v[r-1].nota;
    v[m].codigo = v[r-1].codigo;

    v[r-1].nota = t;
    v[r-1].codigo = k;

    if(v[l].codigo > v[r-1].codigo)
    {
        int tmp = v[l].nota;
        v[l].nota = v[r-1].nota;
        v[r-1].nota = tmp;

        unsigned long int tmp2 = v[l].codigo;
        v[l].codigo = v[r-1].codigo;
        v[r-1].codigo = tmp2;

    }
    if(v[r].codigo < v[l].codigo)
    {
        int tmp = v[r].nota;
        v[r].nota = v[l].nota;
        v[l].nota = tmp;

        unsigned long int tmp2 = v[r].codigo;
        v[r].codigo = v[l].codigo;
        v[r].codigo = tmp2;

    }
    if(v[m].codigo < v[r-1].codigo)
    {
        int tmp = v[r].nota;
        v[r].nota = v[r-1].nota;
        v[r-1].nota = tmp;

        unsigned long int tmp2 = v[r].codigo;
        v[r].codigo = v[r-1].codigo;
        v[r-1].codigo = tmp2;

    }
    int j = separaPorCodigo(v,l,r);
    quickSortCodigo(v,l,j-1);
    quickSortCodigo(v,j+1,r);


}

void quickSelectNota(guardaNumeros *v, int p, int l, int r)
{
    int j = separaPorNota(v,l,r);
    if(j == p) return;
    if(j<p)
        quickSelectNota(v,p,j+1,r);
    else
        quickSelectNota(v,p,l,j-1);
}

void quickSelectCodigo(guardaNumeros *v, int p, int l, int r)
{
    int j = separaPorNota(v,l,r);
    if(j == p) return;
    if(j<p)
        quickSelectCodigo(v,p,j+1,r);
    else
        quickSelectCodigo(v,p,l,j-1);
}


int main()
{
    int k=0;
    scanf("%d",&k);
    guardaNumeros v[100000];
    int i=0;
	while(scanf("%ld %d",&v[i].codigo,&v[i].nota)!=EOF && i<10000000)
        i++;


	quickSelectNota(v,k-1,0,i-1);
	quickSortNota(v,0,k-1);

	quickSelectCodigo(v,k-1,0,i-1);
	quickSortCodigo(v,0,k-1);


	for(i = 0;i<k;i++)
	{
		printf("%ld %d\n",v[i].codigo,v[i].nota);

	}

    return 0;
}
