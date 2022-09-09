#include <stdlib.h>

void insertionSort(int *v, int leftIndex, int rightIndex)
{
    int temporaryValue = 0;
    for(int i = leftIndex; i < rightIndex; i++)
    {

        if(v[i] > v[i+1])
        {
            temporaryValue = v[i];
            v[i] = v[i+1];
            v[i+1] = temporaryValue;

        }
    }
    for(int i = leftIndex; i < rightIndex; i++)
    {
        for(int j = i+1; j > leftIndex; j--)
        {
            if(v[j] < v[j-1])
            {
                temporaryValue = v[j-1];
                v[j-1] = v[j];
                v[j] = temporaryValue;
            }
            else break;
        }
    }

}

//result is an output buffer which has to be filled with the solution
void two_oldest_ages(size_t n, int ages[n], int result[2]) {
  insertionSort(ages,0,n-1);
    
  result[0] = ages[n-2];
  result[1] = ages[n-1];
  
}
