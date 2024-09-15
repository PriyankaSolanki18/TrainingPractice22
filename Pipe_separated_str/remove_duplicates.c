/*
2. Write a program that Finds the unique words from a pipe-separated string.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define MAXWORDS 50

int splitWords(char *str, char *words[]);
void findUnique(char *words[], int count);

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
    findUnique(words, count);

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

void findUnique(char *words[], int count)
{
    int uniqueCount = 0;
    char *uniqueWords[MAXWORDS];
    int visited[MAXWORDS] = {0}; // To keep track of already printed words

    printf("Unique wordssss : ");
    for (int i = 0; i < count; i++) {
        if (visited[i] == 1)
            continue;
        printf("%s", words[i]);
        uniqueWords[uniqueCount] = (char *)malloc(strlen(words[i]) + 1);
        strcpy(uniqueWords[uniqueCount], words[i]);
        uniqueCount++;

        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                visited[j] = 1;
            }
        }
        if (i < count - 1) {
            printf("|");
        }
    }
    printf("\n");

    // Free allocated memory for uniqueWords
    for (int i = 0; i < uniqueCount; i++) {
        free(uniqueWords[i]);
    }
}
