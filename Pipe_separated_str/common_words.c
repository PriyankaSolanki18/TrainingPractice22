/*
7. Find Common Words: Write a program that finds and prints the common words between two pipe-separated strings. For example, given apple|orange|banana|grape and banana|kiwi|grape, the output should be banana|grape.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
#define MAXWORDS 100

int main()
{
    char str[2][MAXWORDS];
    char *word1[MAXWORDS];
    char *word2[MAXWORDS];
    
    //Input
    printf("Enter the first string: ");
    fgets(str[0], MAX-1, stdin);
    str[0][strcspn(str[0], "\n")] = '\0'; 

    printf("Enter the second string: ");
    fgets(str[1], MAX-1, stdin);
    str[1][strcspn(str[1], "\n")] = '\0'; 
    
    // counting words in both strings
    int count1=0;
    char *token1=strtok(str[0],"|");
    while(token1 != NULL){
        word1[count1] = (char *)malloc(strlen(token1) + 1);
        strcpy(word1[count1], token1);
        count1++;
        token1 = strtok(NULL,"|");
    }
    
    int count2=0;
    char *token2=strtok(str[1],"|");
    while(token2 != NULL){
        word2[count2] = (char *)malloc(strlen(token2) + 1);
        strcpy(word2[count2],token2);
        count2++;
        token2=strtok(NULL,"|");
    }
    
    //checking
    char *output[MAXWORDS];
    int newCount=0;
    
    for(int i=0;i<count1;i++){
        for(int j=0;j<count2;j++){
            if(strcmp(word1[i],word2[j]) == 0){
                int exists=0;
                for (int k = 0; k < newCount; k++) {
                    if (strcmp(output[k], word1[i]) == 0) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    output[newCount] = (char *)malloc(strlen(word1[i]) + 1);
                    strcpy(output[newCount], word1[i]);
                    newCount++;
                }
                break;
            }
        }
    }
    
    
    //print result
    printf("Output common words are : ");
    for(int i=0;i<newCount;i++){
        if(i>0){
            printf("|");
        }
        printf("%s",output[i]);
        free(output[i]); 
    }
    printf("\n");
    
    // Free allocated memory for word1 and word2
    for (int i = 0; i < count1; i++) {
        free(word1[i]);
    }
    for (int i = 0; i < count2; i++) {
        free(word2[i]);
    }
    
    return 0;
}
