#include <stdio.h>


void contaSete(unsigned long long int n, int x)
{
    if(n == 0)
    {
        printf("%d\n",x);
        return;
    }
    if(n%10 == 7) x++;

    contaSete(n/10,x);

}


int main()
{
    unsigned long long int n=0;
    scanf("%lld",&n);
    contaSete(n, 0);


    return 0;
}
