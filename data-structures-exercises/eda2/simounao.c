#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int contador1 =0, contador2 =0 ;
    int i=0;
    char *str;
    str = malloc(3*sizeof(char));

    char *v = malloc(11*sizeof(char));
    while(scanf("%s",str)!=EOF)
    {
        v[i] = str[0];
        i++;
        if(i == 10)
        {

            for(int j =0; j<10; j++)
            {
               // printf("olaaa ");
                if(v[j] == 's') contador1++;
            }
            if(contador1>1)
            {
                contador2++;
               // printf("\tEIII");
            }
            contador1=0;
            i=0;
        }
    }
    printf("%d\n",contador2);
    free(str);
    free(v);
    return 0;
}

