
int binary1(long long num){
    if(num <= 1) return num;
    return (num%2) + binary1(num/2);
}

int makeTheIntegerZero(int num1, int num2) {
    int count = 0;
    long long num;
    long long num_1 = num1;
    long long num_2 = num2;
    for(int k = 0; k <= 60; k++){
        num = num_1 - k*num_2;
        if(num < k) return -1;
        else{
            count = binary1(num);
            if(count <= k) return k;
        }
    }
    return -1;
}
