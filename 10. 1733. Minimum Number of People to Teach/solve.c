int check(int a[], int b[], int size_a, int size_b) {
    for (int i = 0; i < size_a; i++) {
        if (a[i] == 0) break; 
        for (int j = 0; j < size_b; j++) {
            if (b[j] == 0) break; 
            if (a[i] == b[j]) {
                return 1; 
            }
        }
    }
    return 0; 
}

int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize) {
    int m = languagesSize;
    int arr[n + 1]; 
    int members[m + 1]; 
    
    
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i <= m; i++) {
        members[i] = 0;
    }
    
    int needTeach = 0; 
    
    for (int i = 0; i < friendshipsSize; i++) {
        int u = friendships[i][0]; 
        int v = friendships[i][1]; 
        
 
        if (!check(languages[u - 1], languages[v -1], languagesColSize[u- 1], languagesColSize[v-1])) {
           
            if (members[u] == 0) {
                members[u] = 1;
                needTeach++;
                
                for (int j = 0; j < languagesColSize[u -1]; j++) {
                    arr[languages[u-1][j]]++;
                }
            }
            
            
            if (members[v] == 0) {
                members[v] = 1;
                needTeach++;
                
                for (int j = 0; j < languagesColSize[v - 1]; j++) {
                    arr[languages[v-1][j]]++;
                }
            }
        }
    }
    
    
    int max_lang = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > max_lang) {
            max_lang = arr[i];
        }
    }
    
   
    return needTeach - max_lang;
}
