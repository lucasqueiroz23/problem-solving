#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ht[101][20];

void htInit()
{
    for(int i = 0; i<101; i++)
    {
        for(int j = 0; j<20; j++)
        {
            ht[i][j] = '0';
        }
    }
}

int HashIt(char *str)
{
    int hKey=0;
    int i = 0;
    while(str[i]!='\0')
    {
        hKey+=(i+1)*str[i];
        i++;
    }
    hKey = 19*hKey;

    return hKey%101;

}

int main()
{
    int t = 0;
    scanf("%d",&t);
    while(t>0)
    {
        htInit();
        char *str = malloc(20*sizeof(char));
        int n = 0,menor = 102;
        scanf("%d",&n);
        int countKeys=0;
        while(n>0)
        {

            scanf("%s",str);
            int hash = HashIt(str+4);

            if(str[0] == 'A')
            {
                int index=0,j=4,pivo=0;
                while(index<20)
                {
                    if(ht[hash][index]!= str[j])
                        break;

                    index++;
                    j++;
                    if(ht[hash][index] == '\0' && ht[hash][index]!=str[j])
                    {
                        pivo = 2; ///colisao!
                        break;
                    }
                    if(index==20 || ( (ht[hash][index] == '\0') && ht[hash][index] == str[j]) )
                        pivo = 1;
                }
                if(pivo==1) ///sao entradas iguais
                {
                    n--;
                    continue;
                }

                if(pivo == 2)
                {
                    countKeys++;
                    while(ht[hash][0] != '0')
                    {
                        hash++;
                        if(hash>100)
                            hash = 0;

                    }
					int i = 0;

					j--;
					while(str[j]!='\0')
					{
						//printf("\n\t%c\n",str[j]);
						ht[hash][i] = str[j];
						i++;
						j++;
					}
					ht[hash][i] = '\0';
					n--;
					continue;


                }

                countKeys++;
                ///procura posicao vazia
                while(ht[hash][0] != '0')
                {
                    hash++;
                    if(hash>100)
                        hash = 0;

                }

                //if(hash<menor) menor = hash;
                //printf("\nstrlen(str) = %d\n",(int)strlen(str));
                for(int i = 0 ; i<strlen(str) ; i++)
                {

                    ht[hash][i] = str[j];
                    //printf("%c",ht[hash][i]);
                    j++;
                }
                ht[hash][strlen(str)] = '\0';

            }
            else
            {
                //printf("\nhash: %d\n",hash);
                int i=0,j = 4;
                int count = 0;
                int iguais = 0; //0 para diferente, 1 para iguais
                while(iguais == 0 && count != 101)
                {
                    i = 0;
                    j = 4;

                    while(ht[hash][i]==str[j])
                    {
                        j++;
                        i++;
                        if(ht[hash][i]==str[j] && str[j] == '\0')
                        {
                            iguais = 1;
                            break;
                        }
                    }
                    if(iguais == 1) break;
                    count++;
                    hash++;
                    if(hash>100)
                        hash = 0;


                }
                if(iguais == 0)
                {
                    n--;
                    continue;
                }

                if(count == 101 )
                {
                    if(iguais == 0)
                    {
                        n--;
                        continue;
                    }
                }

                if(iguais == 1)
                {
                    //printf("sao iguais, hash :%d\n",hash);
                    for(int i = 0; i<20; i++)
                    {
                        ht[hash][i] = '0';
                    }
                }

                countKeys--;
            }


            n--;
        }


        printf("%d\n",countKeys);
        for(int i = 0; i<101; i++)
            if(ht[i][0]!='0')
                printf("%d:%s\n",i,ht[i]);

        free(str);
        t--;
    }

    return 0;
}
