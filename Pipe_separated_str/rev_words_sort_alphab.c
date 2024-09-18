
//Reverse the Characters of Each Word and Then Sort Alphabetically: Write a program that first reverses each individual word in a pipe-separated string and then sorts the reversed words alphabetically. For example, for input apple|banana|grape, the output should be elppa|ananab|eparg.
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

int main() {
    char str[MAX];
    char *words[MAX];
    
    printf("Enter a string : ");
    fgets(str,MAX-1,stdin);
    int len=strlen(str);
    if(str[len-1]=='\n')
    str[len-1]='\0';
    
    int count=0;
    char *token=strtok(str,"|");
    while(token != NULL){
        words[count]=token;
        int start=0;
        int end=strlen(words[count]) - 1;
        while(start<=end){
            char temp = words[count][start];
            words[count][start]=words[count][end];
            words[count][end]=temp;
            start++;
            end--;
        }
        count++;
        token=strtok(NULL,"|");
    }
    //sorting alphabatically after reversing individual word
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(strcmp(words[i],words[j]) > 0){
                char *temp=words[i];
                words[i]=words[j];
                words[j]=temp;
            }
        }
    }
    //output
    for(int i=0;i<count;i++){
        if(i>0)
        printf("|");
        printf("%s",words[i]);
    }
    printf("\n");
    
    return 0;
}
