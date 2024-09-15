/*
8. Count Occurrences of Each Word: Write a program that counts the occurrences of each word in a pipe-separated string and prints the results. For example, for input apple|orange|banana|apple|grape|banana|apple, the output should be:
apple: 3
orange: 1
banana: 2
grape: 1
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
#define MAXWORDS 50

int main()
{
    char str[MAX];
    char *words[MAXWORDS];
    // Array to store word counts
    int wordCount[MAXWORDS] = {0}; 
    
    printf("Enter string : ");
    fgets(str,MAX-1,stdin);
    int len=strlen(str);
    if(str[len-1]=='\n')
    str[len-1]='\0';
    
    int count=0;
    char *token=strtok(str,"|");
    while(token != NULL){
        words[count]=token;
        count++;
        token=strtok(NULL,"|");
    }
    
    //check
    
    for(int i=0;i<count;i++){
        if (wordCount[i] == 0) { // If this word has not been counted yet
            int freq = 1;
            for (int j = i + 1; j < count; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    freq++;
                    wordCount[j] = -1; // Mark as counted
                }
            }
            wordCount[i] = freq;
        }
    }
    
     // Print results
    printf("Counting frequencies:\n");
    for (int i = 0; i < count; i++) {
        if (wordCount[i] > 0) { // Print only words that are counted
            printf("%s: %d\n", words[i], wordCount[i]);
        }
    }
    
    return 0;
}
