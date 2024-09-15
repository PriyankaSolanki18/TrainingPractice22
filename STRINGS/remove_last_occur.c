/*
Write a C program to remove from last occurrence of a word in given string
	Example
Input
Input string: I am a programmer. I learn at Codeforwin.
Input word to remove: I
Output
String after removing last occurrence of 'I':
I am a programmer.  learn at Codeforwin
*/
#include <stdio.h>
#include <string.h>
 
int main() {
    char str[200], word[20];
    int i, j, k, pos = -1;
    int strLen, wordLen;
 
    // Input the string
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Removing trailing newline character
 
    // Input the word to be removed
    printf("Enter the word to remove: ");
    scanf("%s", word);
 
    strLen = strlen(str);
    printf("Str length : %d\n",strLen);
    wordLen = strlen(word);
    printf("Word length : %d\n",wordLen);
 
    // Search for the last occurrence of the word in the string
    for (i = 0; i <= strLen - wordLen; i++) {
        for (j = 0; j < wordLen; j++) {
            if (str[i + j] != word[j]) {
                break;
            }
        }
        if (j == wordLen) {
            pos = i; // Update position to the last found occurrence
        }
    }
 
    // If word is found
    if (pos != -1) {
        // Shift the remaining characters to the left
        for (k = pos; k <= strLen - wordLen; k++) {
            str[k] = str[k + wordLen];
        }
        str[strLen - wordLen] = '\0'; // Terminate the string
        printf("Modified string: %s\n", str);
    } else {
        printf("Word not found in the string.\n");
    }
 
    return 0;
}
