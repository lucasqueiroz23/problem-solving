#include <stdlib.h>

#define UNDERSCORE 10000

int cmpFunc(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b);
}

int removeDuplicates(int* nums, int numsSize){
    int k = 0;
    for(int i = 0; i < numsSize; i++) {
        
        int target = nums[i];
        if(target == UNDERSCORE) continue;

        int j = i + 1;
        while(j < numsSize && nums[j] == target) {
            nums[j] = UNDERSCORE;
            j++;
        }
        k++;
    }
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    return k;
}
