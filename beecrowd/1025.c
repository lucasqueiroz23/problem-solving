#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int leftIndex, int middleIndex, int rightIndex)
{
    int *v2 = malloc(sizeof(int)*(rightIndex-leftIndex+1));

    int k = 0;  // k is an index that will be used to traverse through v2
    int i = leftIndex;
    int j = middleIndex+1;

    while(i<=middleIndex && j<=rightIndex)
    {
        if(v[i]<=v[j])
        {
            v2[k++] = v[i++];
        }
        else v2[k++] = v[j++];
    }

    while(i<=middleIndex)
        v2[k++] = v[i++];
    while(j<=rightIndex)
        v2[k++] = v[j++];

    k=0;

    for(i = leftIndex; i<=rightIndex; i++)
    {
        v[i] = v2[k++];
    }


    free(v2);

}

void mergeSort(int *v, int leftIndex, int rightIndex)
{
    if(leftIndex>=rightIndex) return;
    int middleIndex = (leftIndex+rightIndex)/2;
    mergeSort(v,leftIndex,middleIndex);
    mergeSort(v,middleIndex+1,rightIndex);
    merge(v,leftIndex,middleIndex,rightIndex);

}

int binarySearch(int *array, int arraySize, int targetValue)
{
    int leftIndex = 0;
    int rightIndex = arraySize-1;

    if(array[leftIndex] == targetValue) return leftIndex;
    if(array[rightIndex] == targetValue)
    {
		while(array[rightIndex-1] == targetValue) rightIndex--;
        return rightIndex;
    }

    while(leftIndex < rightIndex -1)
    {
        int middleIndex = (leftIndex + rightIndex)/2;
        if(array[middleIndex] == targetValue)
        {
            while(array[middleIndex-1] == targetValue) middleIndex--;
            return middleIndex;
        }

        if(array[middleIndex] < targetValue) leftIndex = middleIndex;
        else rightIndex = middleIndex;
    }

    return -1;
}

int main()
{
    int n=0,q=0;
    scanf("%d%d",&n,&q);
    int count = 1;
    while(q!=0 && n!=0)
    {
        int maior = -1;
        int *ar = malloc(n*sizeof(int));
        int *ht = calloc(10001, sizeof(int));


        for(int i = 0; i<n; i++)
        {
            scanf("%d",&ar[i]);
            ht[ar[i]]++;
            if(ar[i]>maior)
                maior = ar[i];
        }

        mergeSort(ar,0,n-1);
        printf("CASE# %d:\n",count);

        for(int i = 0; i<q; i++)
        {
            int val = 0;
            scanf("%d",&val);

            if(ht[val] == 0)
            {
                printf("%d not found\n",val);
                continue;
            }

            int pos = binarySearch(ar,n,val);
            printf("%d found at %d\n",val,pos+1);


        }

        free(ar);
        free(ht);
        count++;
        scanf("%d%d",&n,&q);
    }

    return 0;
}
