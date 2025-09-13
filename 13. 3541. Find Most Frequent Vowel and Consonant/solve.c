int maxFreqSum(char* s) {
    const bool lookup[256] = {
        ['a'] = true, ['e'] = true, ['i' ] = true, ['o'] = true, ['u'] = true
    };
    int arr[256] = {0};
    int max_vowel = 0;
    int max_fre = 0;
    for(int i = 0; s[i] != '\0'; i++){
        arr[s[i]] ++;
        if(lookup[s[i]]) max_vowel = max_vowel > arr[s[i]] ?  max_vowel : arr[s[i]];
        else max_fre = max_fre > arr[s[i]] ?  max_fre : arr[s[i]];
    }

    return max_fre + max_vowel;
}
