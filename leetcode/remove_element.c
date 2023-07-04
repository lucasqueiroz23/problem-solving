void swap(int* arr, int pos1, int pos2) {
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int removeElement(int* nums, int numsSize, int val){
    int not_equal_count = 0;
    int tail = numsSize - 1;
    for(int i = 0; i < numsSize && nums[i] != -1; i++) {
       if(nums[i] == val) {
           nums[i] = -1;
           swap(nums, i, tail--);
           if(nums[i] == val) i--;
           else if(nums[i] != -1) not_equal_count++;
       } else not_equal_count++;
    }

    // all numbers are equal to target
    if(not_equal_count == 0) {
        for(int i = 0; i < numsSize; i++)
            nums[i] = NULL;
            return 0;
    }
    
    return not_equal_count;
}

