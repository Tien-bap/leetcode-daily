
int check_vowels(char a){
    switch(a){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return 1;
        default :
            return 0;
    }
}


int cmp(const void*a, const void*b){
    char*x = (char*)a;
    char*y = (char*)b;
    if(*x < *y ) return -1;
    if(*x > *y ) return 1;
    return 0;
}

char* sortVowels(char* s) {
    int size_s = strlen(s);
    char*vowels = (char*)malloc(sizeof(char)*size_s);
    int size = 0;
    for(int i = 0; i < size_s; i++){
        if(check_vowels(s[i])) {
            vowels[size ++ ] = s[i];
        }
    }

    qsort(vowels, size, sizeof(char), cmp );

    int cur = 0;
    for(int i = 0; i < size_s; i++){
        if(check_vowels(s[i])) {
            s[i] = vowels[cur ++ ];
        }
    }
    free(vowels);
    return s;

}
