//Palindrome string or not:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
//----------------------------------------------
 
//PALINDROME
int isPalindrome(char *str) {
    int low = 0;
    int high = strlen(str) - 1;
 
    while (low < high) {
        if (str[low] != str[high]) {
            return 0; // not a palindrome
        }
        low++;
        high--;
    }
    return 1; // is a palindrome
}
 
//-----------------------------------------------
 
int main() {
    char *str1 = NULL;
    str1 = (char *)malloc(MAX * sizeof(char));
    if (str1 == NULL) {
        printf("Memory allocation failed\n");
        free(str1);
        return EXIT_FAILURE;
    }
    printf("Enter your string : ");
    if (fgets(str1, MAX, stdin) == NULL) {
        printf("Error in fgets\n");
        free(str1);
        return EXIT_FAILURE;
    }
    int len1 = strlen(str1);
    if (len1 > 0 && str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
        len1--;
    }
//-----------------------------------------------
// PALINDROME
if (isPalindrome(str1)) {
        printf("String is Palindrome\n");
    } else {
        printf("String is not Palindrome\n");
    }
//------------------------------------------------
    free(str1);
    return EXIT_SUCCESS;
}
