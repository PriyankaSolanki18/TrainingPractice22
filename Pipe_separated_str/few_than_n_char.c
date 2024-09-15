/*
6. Write a program that removes words with fewer than N characters from a pipe-separated string. For example, for input apple|kiwi|banana|grape with N = 5, the output should be apple|banana|grape.
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
    
    printf("Enter string : ");
    fgets(str,MAX-1,stdin);
    int len=strlen(str);
    if(str[len-1]=='\n')
    str[len-1]='\0';
    
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    
    int count = 0;
    char *token=strtok(str,"|");
    while(token != NULL){
        words[count] = token;
        count++;
        token=strtok(NULL,"|");
    }
    
    //checking
    int newCount=0;
    for(int i=0;i<count;i++){
        int len = strlen(words[i]);
        if(len >= n){
            words[newCount++]=words[i];
        }
    }
    
    //printing
    for(int i=0;i<newCount;i++){
        if(i>0){
            printf("|");
        }
        printf("%s",words[i]);
    }
    printf("\n");
    
    return 0;
}
