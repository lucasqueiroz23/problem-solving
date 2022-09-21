#include <stdio.h>
#include <stdlib.h>

int ht[1000000];

int main()
{
    int n=0;
    for(int i = 0;i<1000000;i++)
		ht[i] = 0;

    while(1)
    {
		scanf("%d",&n);
		if(n == 0 ) break;

        int *v=malloc(n*sizeof(int));
        for(int i = 0;i<n;i++)
        {
			int val=0;
			scanf("%d",&val);
			val = val%1000000;
			ht[val]+=1;
			v[i] = val;

        }
        int maior = -1;
        int valorQueApareceMais=0;
        for(int i = 0; i<n; i++)
        {
			if( ht[v[i]] > maior )
			{
				maior = ht[v[i]];
				valorQueApareceMais = v[i];
			}

        }
        for(int i = 0;i<n;i++)
			ht[v[i]] = 0;
        printf("%d\n",valorQueApareceMais);

        free(v);
    }



    return 0;
}
