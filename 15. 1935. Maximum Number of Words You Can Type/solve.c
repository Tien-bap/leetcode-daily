int canBeTypedWords(char* text, char* brokenLetters) {
    bool lookup[256] = {false};
    for(int i = 0 ; brokenLetters[i] != '\0'; i++){
        lookup[brokenLetters[i]] = true;
    }
    int count = 0;
    bool cantype = true;
    int i = 0;
    while(text[i] != '\0'){
        cantype = true;
        while(text[i] == ' ') i++;
        while(text[i] != ' ' && text[i] != '\0'){
            if(lookup[text[i]]) cantype = false;
            i ++;
        }

        if(cantype) count++;
    }
    return count;
}
