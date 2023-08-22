int searchInsert(int* nums, int numsSize, int target){
    // we'll solve it with a binary search
    int left = 0;
    int right = numsSize - 1;

    // check if it's 
    if(target == nums[left]) return left;
    if(target == nums[right]) return right;
    int mid = 0;

    while(right > left + 1) {
        mid = (left + right)/2;
        if(nums[mid] == target) return mid; 
        if(nums[mid] > target) 
            right = mid;
        else left = mid;
    }
    if(target > nums[right]) return right + 1;
    if(target < nums[left]) {
        return left == 0 ? left : left - 1; 
    }
    return right;
}
