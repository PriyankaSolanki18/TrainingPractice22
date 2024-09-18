// Merge Two Pipe-Separated Strings: Write a program that merges two pipe-separated strings into one, ensuring that there are no duplicate words in the resulting string. For example, for input apple|banana|grape and banana|kiwi|orange, the output should be apple|grape|kiwi|orange.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main() {
    char str[2][MAX];
    char *words1[MAX];
    char *words2[MAX];

    printf("Enter 1st string: ");
    fgets(str[0], MAX - 1, stdin);
    str[0][strcspn(str[0], "\n")] = '\0';

    printf("Enter 2nd string: ");
    fgets(str[1], MAX - 1, stdin);
    str[1][strcspn(str[1], "\n")] = '\0';

    // Tokenize the first string
    int count1 = 0;
    char *token1 = strtok(str[0], "|");
    while (token1 != NULL) {
        words1[count1++] = token1;
        token1 = strtok(NULL, "|");
    }

    // Tokenize the second string
    int count2 = 0;
    char *token2 = strtok(str[1], "|");
    while (token2 != NULL) {
        words2[count2++] = token2;
        token2 = strtok(NULL, "|");
    }

    // Merging the two arrays of words
    int count3 = count1 + count2;
    char *words3[MAX];
    for (int i = 0; i < count1; i++) {
        words3[i] = words1[i];
    }
    for (int j = 0; j < count2; j++) {
        words3[count1 + j] = words2[j];
    }
    
    //printing after merging
    printf("printing after merging : \n");
    for(int i=0;i<count3;i++){
        if(i>0)
        printf("|");
        printf("%s",words3[i]);
    }

    // Removing duplicates
    int uniqueCount = 0;
    for (int i = 0; i < count3; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(words3[i], words3[j]) == 0) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            words3[uniqueCount++] = words3[i];
        }
    }

    // Printing the merged array after removing duplicates
    printf("\nOutput string is:\n");
    for (int i = 0; i < uniqueCount; i++) {
        if (i > 0) {
            printf("|");
        }
        printf("%s", words3[i]);
    }
    printf("\n");

    return 0;
}
