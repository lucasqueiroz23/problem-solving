#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r)
{
    int *v2 = malloc((r-l+1)*sizeof(int));
    int k = 0;
    int i = l;
    int j = m+1;

    while(i <= m && j<=r)
    {
        if(v[i]<=v[j])
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }
    while(i<=m)
        v2[k++] = v[i++];
    while(j<=r)
        v2[k++] = v[j++];

    k = 0;

    for(i = l;i <= r; i++)
        v[i] = v2[k++];

    free(v2);
}

void mergeSort(int *v, int l, int r)
{
    if(l>=r) return;
    int m = (r+l)/2;
    mergeSort(v,l,m);
    mergeSort(v,m+1,r);
    merge(v,l,m,r);

}

int buscaBinaria(int *v, int tam, int num)
{
    int l = 0, r = tam-1;
    while(l<r-1)
    {
        int mid = (l+r)/2;
        if(v[mid] == num) return mid;
        if(v[l] == num) return l;
        if(v[r] == num) return r;

        if(num > v[mid]) l = mid;
        if(num < v[mid]) r = mid;

    }


    return -1;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int *v = malloc(n*sizeof(int));
    for(int i=0 ; i<n ; i++)
        scanf("%d",&v[i]);

    mergeSort(v,0,n-1);
    int num = 0;
    while(scanf("%d",&num)!=EOF)
    {
        int pos = buscaBinaria(v,n,num);
        if(pos == -1)
            printf("nao\n");
        else printf("sim\n");
    }


    free(v);
    return 0;
}
