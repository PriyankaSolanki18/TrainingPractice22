/*
5. Write a program that splits a pipe-separated string into words and reverses the order of the words. For example, the input apple|banana|grape|orange should return orange|grape|banana|apple.
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
    
    int count = 0;
    char *token=strtok(str,"|");
    while(token != NULL){
        words[count] = (char *)malloc(strlen(token) + 1);
        strcpy(words[count],token);
        count++;
        token=strtok(NULL,"|");
    }
     int start=0;
        int end=count-1;
        while(start<=end){
            char *temp=words[start];
            words[start]=words[end];
            words[end]=temp;
            start++;
            end--;
        }
    
    
    //print output
    for(int i=0;i<count;i++){
        if(i>0){
            printf("|");
        }
        printf("%s",words[i]);
    }
    printf("\n");
    
    //free
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    
    return 0;
}
