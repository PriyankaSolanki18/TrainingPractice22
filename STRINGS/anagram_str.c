//Anagrams
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX 20
 
void sortString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[j] < str[i]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
 
int main() {
    char *str1 = NULL;
    char *str2 = NULL;
 
    str1 = (char *)malloc(MAX * sizeof(char));
    str2 = (char *)malloc(MAX * sizeof(char));
 
    if (str1 == NULL || str2 == NULL) {
        printf("Memory allocation failed\n");
        free(str1);
        free(str2);
        return EXIT_FAILURE;
    }
 
    if (fgets(str1, MAX, stdin) == NULL) {
        printf("Error in fgets\n");
        free(str1);
        free(str2);
        return EXIT_FAILURE;
    }
 
    if (fgets(str2, MAX, stdin) == NULL) {
        printf("Error in fgets\n");
        free(str1);
        free(str2);
        return EXIT_FAILURE;
    }
 
    int len1 = strlen(str1);
    if (len1 > 0 && str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
        len1--;
    }
 
    int len2 = strlen(str2);
    if (len2 > 0 && str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
        len2--;
    }
 
    if (len1 != len2) {
        printf("strings are not anagram\n");
    } else {
        sortString(str1);
        sortString(str2);
 
        if (strcmp(str1, str2) == 0) {
            printf("strings are anagram\n");
        } else {
            printf("strings are not anagram\n");
        }
    }
 
    free(str1);
    free(str2);
    return 0;
}
