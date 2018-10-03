int removeDuplicates(int* nums, int numsSize) {
    if(numsSize < 2) return numsSize;
        int id = 1;
        for(int i = 1; i < numsSize; ++i) 
            if(nums[i] != nums[i-1]) nums[id++] = nums[i];
        return id;
}