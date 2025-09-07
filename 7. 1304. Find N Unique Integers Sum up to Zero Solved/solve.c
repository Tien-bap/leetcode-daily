int* sumZero(int n, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int)*n);
    *returnSize = n;
    int i = 0;
    int j = n-1;
    int k = n/2;
    while(i <= j){
        arr[i] = -k;
        arr[j] = k;
        k --;
        i++;
        j--;
    }
    return arr;
}
