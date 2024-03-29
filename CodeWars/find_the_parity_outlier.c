#include <stdlib.h>
#include <stdlib.h>

typedef int DATA_TYPE;

void insertionSort(DATA_TYPE *v, int leftIndex, int rightIndex)
{
    int temporaryValue=0;
    for(int i=leftIndex; i<rightIndex; i++)
    {

        if(v[i]>v[i+1])
        {
            temporaryValue=v[i];
            v[i]=v[i+1];
            v[i+1]=temporaryValue;

        }
    }
    for(int i=leftIndex; i<rightIndex; i++)
    {
        for(int j = i+1; j>leftIndex; j--)
        {
            if(v[j]<v[j-1])
            {
                temporaryValue = v[j-1];
                v[j-1] = v[j];
                v[j] = temporaryValue;
            }
            else break;
        }
    }

}

int partition(DATA_TYPE *v,int leftIndex, int rightIndex)
{

    DATA_TYPE valueToCompare = v[rightIndex];
    int j = leftIndex;

    for(int k = leftIndex; k< rightIndex ; k++)
        if(v[k]<=valueToCompare)
        {

            int temporaryValue = v[k];
            v[k] = v[j];
            v[j] = temporaryValue;
            j++;

        }

    int temporaryValue = v[j];
    v[j] = v[rightIndex];
    v[rightIndex] = temporaryValue;


    return j;


}

void quickSort(DATA_TYPE *v, int leftIndex, int rightIndex)
{

    if(rightIndex-leftIndex<=32)
    {
        insertionSort(v,leftIndex,rightIndex);
        return;

    }
    int middleIndex = (leftIndex+rightIndex)/2;

    DATA_TYPE middleValue = v[middleIndex];
    v[middleIndex] = v[rightIndex-1];
    v[rightIndex-1] = middleValue;

    if(v[leftIndex]>v[rightIndex-1])
    {
        DATA_TYPE temporaryValue = v[leftIndex];
        v[leftIndex] = v[rightIndex-1];
        v[rightIndex-1] = temporaryValue;
    }

    if(v[rightIndex]<v[leftIndex])
    {
        DATA_TYPE temporaryValue = v[rightIndex];
        v[rightIndex] = v[leftIndex];
        v[leftIndex] = temporaryValue;
    }

    if(v[middleIndex]<v[rightIndex-1])
    {
        DATA_TYPE temporaryValue = v[rightIndex];
        v[rightIndex] = v[rightIndex-1];
        v[rightIndex-1] = temporaryValue;
    }


    int j = partition(v,leftIndex,rightIndex);
    quickSort(v,leftIndex,j-1);
    quickSort(v,j+1,rightIndex);


}

int find_outlier( int *values, size_t count){
  int oddPos = 0, countOdd = 0;
  int evenPos = 0, countEven = 0;
  
  
  quickSort(values,0,count-1);
  
  for(size_t i = 0; i< count; i++){
    if(values[i]%2 == 0){
      evenPos = i;
      countEven++;
    }
    else{
      oddPos = i;
      countOdd++;
    }
    
    if(countEven>countOdd && countOdd>0){
      return values[oddPos];
    }
    if(countOdd>countEven && countEven>0){
      return values[evenPos];
    }
    
  }
  
}
