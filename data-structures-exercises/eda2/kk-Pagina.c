#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *v, int l, int r)
{
    int tmp=0;
    for(int i=l;i<r;i++)
    {

        if(v[i]>v[i+1])
        {
            tmp=v[i];
            v[i]=v[i+1];
            v[i+1]=tmp;

        }
    }
    for(int i=l;i<r;i++)
    {
        for(int j = i+1;j>l;j--)
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

void quickSelect(int *v, int p, int l, int r)
{
    int j = separa(v,l,r);
    if(j==p) return;
    if(j<p)
        quickSelect(v,p,j+1,r);
    else
        quickSelect(v,p,l,j-1);

}

int main()
{
    int x=0,n=0,p=0;
    scanf("%d %d %d",&n,&p,&x);
    int *v = malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&v[i]);
    }

    int pagInicio = p*x;
    int pagFim = p*x+x;
    if(pagFim > n-1)
        pagFim = n-1;

	quickSelect(v,pagInicio,0,n-1);
	if(pagFim != pagInicio){
	quickSelect(v,pagFim,pagInicio+1,n-1);
	quickSort(v,pagInicio,pagFim);
	}

    int count = 0;
    while(pagInicio<n && count < x)
    {
        printf("%d\n",v[pagInicio]);
        pagInicio++;
        count++;
    }


    free(v);
    return 0;
}
