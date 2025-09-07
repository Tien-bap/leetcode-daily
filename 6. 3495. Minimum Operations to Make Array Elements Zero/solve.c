long long minOperations(int** queries, int queriesSize, int* queriesColSize) {
    long long cnt = 0;
    int l, r;
    int start_k;
    int end_k;
    int start;
    int end;
    for(int i = 0; i < queriesSize; i++){
        long long temp = 0;
        l = queries[i][0];
        r = queries[i][1];
        start_k = floor(log(l)/log(4));
        end_k = floor(log(r)/log(4)) ;
        for(int k = start_k; k <= end_k; k++){
            start = pow(4, k) - l > 0 ? pow(4, k) : l;
            end = pow(4, k+1) - 1 -  r < 0 ? pow(4, k+1) - 1 :  r ;
            temp += (long long)(end - start + 1)*(k+1);
        }
        cnt += (temp+1)/2;
    }

    return cnt;
}
