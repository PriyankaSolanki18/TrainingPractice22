/*You are given a string, str.
You need to find the score of str as per the following rules:
1) For each palindrome of length 4 in str, add 5 to the score
2) For each palindrome of length 5 in str, add 10 to the score
 
It is given that palindromes can overlap within str. However, the characters of the palindrome must be continuous and must NOT be circular (i.e. they must NOT wrap around the end of the string.
 
Output the final value of score.
 
Notes:
• A palindrome is a word, phrase, or sequence that reads the same backwards as forwards. Examples of palindromes are words like "madam", "racecar", "abCba" and "aBccBa", and "ABBA"
• Palindromes are case-sensitive in this problem (e.g. "Madam" and "ABCcba" are NOT palindromes)
• The score is initially 0
• There are no whitespaces in str.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX 30
 
// Function to check if a substring is a palindrome
int isPalindrome(char *str, int start, int length) {
    int end = start + length - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
 
int main() {
    char *str = NULL;
    int score = 0;
 
    // Allocate memory for the string
    str = (char *)malloc((MAX + 1) * sizeof(char));
    if (str == NULL) {
        printf("Malloc Failed");
        return EXIT_FAILURE;
    }
 
    printf("Enter string to check palindrome: ");
    if (fgets(str, MAX + 1, stdin) == NULL) {
        printf("fgets failed");
        free(str);
        return EXIT_FAILURE;
    }
 
    // Remove newline character if present
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
 
    // Check for palindromes of length 4 and 5
    for (int i = 0; i <= len - 4; i++) {
        if (isPalindrome(str, i, 4)) {
            score += 5;
        }
    }
    for (int i = 0; i <= len - 5; i++) {
        if (isPalindrome(str, i, 5)) {
            score += 10;
        }
    }
 
    printf("The score is: %d\n", score);
 
    // Free allocated memory
    free(str);
 
    return EXIT_SUCCESS;
}
