/*
4. Write a program that reverses each individual word in a pipe-separated string while keeping the original order of words. For example, the input apple|banana|grape should return elppa|ananab|eparg.
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
    
    printf("Enter pipe separated string : ");
    fgets(str,MAX-1,stdin);
    int len = strlen(str);
    if(str[len-1]=='\n')
    str[len-1]='\0';
    
    int count=0;
    char *token=strtok(str,"|");
    while(token != NULL){
        words[count] =token;
        int start=0;
        int end=strlen(words[count])-1;
        while(start<=end){
            char temp=words[count][start];
            words[count][start]=words[count][end];
            words[count][end]=temp;
            start++;
            end--;
        }
        count++;
        token=strtok(NULL,"|");
    }
    
    //print output
    for(int i=0;i<count;i++){
        printf("%s",words[i]);
        if(i<count-1){
            printf("%c",'|');
        }
    }
    printf("\n");
    
    return 0;
}
