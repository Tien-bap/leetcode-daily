
typedef struct {
    char key[101];   // key đã chuẩn hóa
    char *value;     // từ gốc trong wordlist
    UT_hash_handle hh;
} HashMap;

void normalize_lowercase(char *dst, const char *src) {
    int i = 0;
    while (src[i]) {
        dst[i] = tolower(src[i]);
        i++;
    }
    dst[i] = '\0';
}

void normalize_vowel(char *dst, const char *src) {
    int i = 0;
    while (src[i]) {
        char c = tolower(src[i]);
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            dst[i] = '*';
        else
            dst[i] = c;
        i++;
    }
    dst[i] = '\0';
}

char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize) {
    *returnSize = queriesSize;
    char** result = (char**)malloc(sizeof(char*) * queriesSize);

    HashMap *map_orig = NULL, *map_lower = NULL, *map_vowel = NULL, *entry;

    char tmp1[101], tmp2[101];

    // build hash maps
    for (int i = 0; i < wordlistSize; i++) {
        // exact map
        entry = malloc(sizeof(HashMap));
        strcpy(entry->key, wordlist[i]);
        entry->value = wordlist[i];
        HASH_ADD_STR(map_orig, key, entry);

        // lowercase map (chỉ thêm nếu chưa tồn tại)
        normalize_lowercase(tmp1, wordlist[i]);
        HASH_FIND_STR(map_lower, tmp1, entry);
        if (!entry) {
            entry = malloc(sizeof(HashMap));
            strcpy(entry->key, tmp1);
            entry->value = wordlist[i];
            HASH_ADD_STR(map_lower, key, entry);
        }

        // vowel map (chỉ thêm nếu chưa tồn tại)
        normalize_vowel(tmp2, wordlist[i]);
        HASH_FIND_STR(map_vowel, tmp2, entry);
        if (!entry) {
            entry = malloc(sizeof(HashMap));
            strcpy(entry->key, tmp2);
            entry->value = wordlist[i];
            HASH_ADD_STR(map_vowel, key, entry);
        }
    }

    // process queries
    for (int i = 0; i < queriesSize; i++) {
        char *q = queries[i];

        // exact match
        HASH_FIND_STR(map_orig, q, entry);
        if (entry) {
            result[i] = strdup(entry->value);
            continue;
        }

        // lowercase match
        normalize_lowercase(tmp1, q);
        HASH_FIND_STR(map_lower, tmp1, entry);
        if (entry) {
            result[i] = strdup(entry->value);
            continue;
        }

        // vowel match
        normalize_vowel(tmp2, q);
        HASH_FIND_STR(map_vowel, tmp2, entry);
        if (entry) {
            result[i] = strdup(entry->value);
            continue;
        }

        // not found
        result[i] = strdup("");
    }

    return result;
}
