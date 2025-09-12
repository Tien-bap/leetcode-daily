bool doesAliceWin(char* s) {
    int cnt = 0;
    const bool arr[256] = {
        ['a'] = true, ['e'] = true, ['i'] = true, ['o'] = true, ['u'] = true
    };

    for(int i = 0; s[i] != '\0'; i++){
        if(arr[s[i]]) return true;
    }
    
    return false;
}
