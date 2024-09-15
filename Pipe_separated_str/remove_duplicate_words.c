/*
1. Write a program that removes duplicate words from a pipe-separated string.
For example, the input apple|orange|banana|apple|grape should return apple|orange|banana|grape.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define MAXWORDS 50

int splitWords(char *str, char *words[]);
void removeDuplicate(char *words[], int *count);

int main()
{
    char str[MAX];
    char *words[MAXWORDS]; // Increased MAXWORDS to accommodate more words
    printf("Enter pipe separated words: ");
    fgets(str, MAX-1, stdin);

    // Remove the trailing newline character if present
    int len = strlen(str);
    if (str[len-1] == '\n')
        str[len-1] = '\0';

    int count = splitWords(str, words);
    removeDuplicate(words, &count);

    // Print the result
    printf("After removing duplicate words : ");
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            printf("|");
        }
        printf("%s", words[i]);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }

    return 0;
}

int splitWords(char *str, char *words[])
{
    int count = 0;
    char *token = strtok(str, "|");
    while (token != NULL) {
        words[count] = (char *)malloc(strlen(token) + 1); // Allocate memory based on the length of the token
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, "|");
    }
    return count;
}

void removeDuplicate(char *words[], int *count)
{
    int visited[MAXWORDS] = {0};
    int k;

    for (int i = 0; i < *count; i++) {
        if (visited[i] == 1)
            continue;

        for (int j = i + 1; j < *count; j++) {
            if (strcmp(words[i], words[j]) == 0) { // Use strcmp to compare strings
                free(words[j]); // Free the memory for the duplicate
                for (k = j; k < *count - 1; k++) {
                    words[k] = words[k + 1];
                }
                words[k] = NULL; // Nullify the last word
                (*count)--; // Decrement the count
                j--; // Adjust index to check the new word in place of the removed one
            }
        }
        visited[i] = 1; // Mark the current word as processed
    }
}

