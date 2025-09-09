int peopleAwareOfSecret(int n, int delay, int forget) {
    long long arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    long long total = 0;
    for(int i = 2; i <= n; i++){
        if(i - forget >= 0) total -= (arr[i-forget] + 1000000007 )%1000000007;
        if(i - delay >= 0) total += (arr[i-delay])%1000000007;
        arr[i] = total;
    }

    for(int i = n-delay + 1; i <= n; i ++){
        total = (total + arr[i]) % 1000000007;

    }
    return (int)total;

}
