#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int n)
{
    int j=0,i=0,sentinela = 1,posfinal=j;
    char strArr[n][21];
    int *notas = malloc(n*sizeof(int));
    int *posMenoresNotas = malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        posMenoresNotas[i] = -1;
    }

    for(i=0; i<n; i++)
    {
        scanf(" %s%d",strArr[i],&notas[i]);
    }
    int menorNota = notas[0];
    for(i=0; i<n; i++)
    {
        if(notas[i] < menorNota)
        {
            menorNota = notas[i];
            j=i; ///guarda a posicao da menor nota em j
        }
    }

    ///esse for serve pra conferir se a menor nota se repete.
    for(i=0; i<n; i++)
    {
        if(notas[i]==menorNota) sentinela=0;
        if(sentinela == 0) break;
        if(i+1==j)i++;
    }

    ///caso a menor nota nao se repita, entao ja podemos finalizar o codigo
    if(sentinela==1)
    {
        printf("%s\n",strArr[j]);
        return;
    }


    for(i=0; i<n; i++)
    {
        if (notas[i] == menorNota)
        {
            posMenoresNotas[i] = menorNota;
        }
    }
    posfinal = j;
    for(i=0;i<n;i++)
    {
        if(posMenoresNotas[posfinal] == posMenoresNotas[i])
        {
            if(strcmp(strArr[j],strArr[i])<0) posfinal=i;
        }

    }

    printf("%s\n",strArr[posfinal]);
    free(notas);
    free(posMenoresNotas);

}

int main()
{
    int k=1,n=0;
    while(scanf("%d",&n) ==1)
    {
    scanf("%d",&n);
        printf("Instancia %d\n",k);
        solve(n);
        k++;

    }

    return 0;
}
