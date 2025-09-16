
int GCD(int a, int b){
    int remain;
    while(b > 0){
        remain = a%b;
        a = b;
        b = remain;
    }
    return a;
}


int LCM(int a, int b, int gcd){
    return (a/gcd)*b;
}

int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {
    int*Stack = (int*)malloc(sizeof(int)*numsSize);
    int top = -1;
    int cur, gcd;
    for(int i = 0; i < numsSize; i++){
        cur = nums[i];
        while(top >= 0){
            gcd = GCD(Stack[top], cur);
            if(gcd == 1) break;
            cur = LCM(Stack[top], cur, gcd);
            top--;
        }
        Stack[++top] = cur;
    }
    *returnSize = top+1;
    return Stack;
}
