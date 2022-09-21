#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int devolveSoma(char *str,int tam)
{
    int soma=0;
    for(int i=0;i<tam;i++)
    {
        switch(str[i])
        {
        case '1': soma+=1;
            break;
        case '2': soma+=2;
            break;
        case '3': soma+=3;
            break;
        case '4': soma+=4;
            break;
        case '5': soma+=5;
            break;
        case '6': soma+=6;
            break;
        case '7': soma+=7;
            break;
        case '8': soma+=8;
            break;
        case '9': soma+=9;
            break;
        default:
            continue;
            break;

        }
    }
    return soma;
}

int main()
{
    int soma=0, n=0;
    char str[100];
    scanf("%d",&n);
    int *v = malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf(" %s",str);
        v[i] = devolveSoma(str,strlen(str));
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",v[i]);
    }

    free(v);
    return 0;
}
