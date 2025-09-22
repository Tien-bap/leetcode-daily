int cmp(const void*a, const void*b){
    int*x = (int*)a;
    int*y = (int*)b;
    if(*x < *y) return -1;
    if(*x > *y) return 1;
    return 0;
}
int maxFrequencyElements(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int i = 1;
    int cnt = 1;
    int fre = 1;
    int max_fre = 1;
    int cur = nums[0];

    while( i < numsSize){
        if(nums[i] == cur) {
            fre ++;
        }
        else{
            if(fre == max_fre) cnt ++;
            else if(fre > max_fre){
                max_fre = fre;
                cnt = 1;
            }
            fre = 1;
            cur = nums[i];
        }
        i++;
    }
    if(fre > max_fre){
        max_fre = fre;
        cnt = 1;
    }
    else if(fre == max_fre && fre > 1) cnt++;
    return max_fre*cnt;
}
