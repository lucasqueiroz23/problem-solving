#include <stdio.h>

int main()
{
    int a=0,N=0;
    scanf("%d",&N);
    int soma=0;

    for(int i=0;i<N;i++)
    {
        scanf("%d",&a);
        soma+=a;
    }

    printf("%d",soma);
    return 0;
}
