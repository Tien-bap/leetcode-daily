int check(int a){
    while(a > 0){
        if(a % 10 == 0) return 0;
        a/= 10;
    }
    return 1;
}

int* getNoZeroIntegers(int n, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    for(int i = 1; i < n; i++){
        if(check(i ) && check(n-i) ){
            result[0] = i;
            result[1] = n-i;
            break;
        }
    }
    return result;
}
