char* cut(char*version, int size, int start, int*end){
    int i;
    for(i = start; i < size; i++){
        if(version[i] == '.'){
            break;
        } 
    }
    *end = i;
    char*result = (char*)malloc(sizeof(char)*(*end - start + 1  ));
    for(int i = start; i < *end; i++){
        result[i - start] = version[i];
    }
    result[*end - start] = '\0';
    return result;
}

int compareVersion(char* version1, char* version2) {
    int size1 = strlen(version1);
    int size2 = strlen(version2);
    int start1 = 0;
    int start2 = 0;
    int end1;
    int end2;
    char*temp1;
    char*temp2;
    int num1, num2;
    while(start1 < size1 && start2 < size2){
        temp1 = cut(version1, size1, start1, &end1);
        temp2 = cut(version2, size2, start2, &end2);
        num1 = atol(temp1);
        num2 = atol(temp2);
        if(num1 < num2) return -1;
        if(num1 > num2) return 1;
        start1 = end1 + 1;
        start2 = end2 + 1;
        free(temp1);
        free(temp2);
    }

    while(start1 < size1){
        temp1 = cut(version1, size1, start1, &end1);
        num1 = atol(temp1);
        if(num1 > 0) return 1;
        start1 = end1 + 1;
        free(temp1);
    }

    while(start2 < size2){
        temp2 = cut(version2, size2, start2, &end2);
        num2 = atol(temp2);
        if(num2 > 0) return -1;
        start2 = end2 + 1;
        free(temp2);
    }
    return 0;
}
