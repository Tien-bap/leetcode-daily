int cmp(const void*a, const void*b){
    return (*(int*)b) - (*(int*)a);
}

int triangleNumber(int* nums, int numsSize) {
    int cnt = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int l, r;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0) continue;
        l = i + 1;
        r = numsSize - 1;
        while(l < r){
            if(nums[l] + nums[r] > nums[i]) {
                cnt += r - l;
                l ++;
            }
            else r --;
        }
    }
    return cnt;
}
