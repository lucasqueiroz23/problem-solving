#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int main()
{
    int n=0,x=0;
    scanf("%d",&n);
    int *v = malloc((MAX+1)*sizeof(int));
    for(int i=0;i<MAX;i++)
    {
        v[i] = 0;
    }
    int soma=0,maior = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x>maior) maior = x;
        if(v[x]==1) continue;
        v[x]++;

    }

    for(int i=0;i<=maior;i++)
    {
        soma+=v[i];
    }
    printf("%d\n",soma);
    return 0;
}
