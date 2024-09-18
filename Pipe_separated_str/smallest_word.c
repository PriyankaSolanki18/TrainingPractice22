
//Find Shortest Word: Write a program that finds and prints the shortest word from a pipe-separated string. For example, for input apple|banana|grape|kiwi, the output should be kiwi.
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100

int main() {
    char str[MAX];
    char *words[MAX];
    
    printf("Enter string : ");
    fgets(str,MAX-1,stdin);
    int len=strlen(str);
    if(str[len-1]=='\n')
    str[len-1]='\0';
     int count=0;
     char *token=strtok(str,"|");
     while(token != NULL){
         words[count] = token;
         count++;
         token=strtok(NULL,"|");
     }
     int minlen=INT_MAX;
     for(int i=0;i<count;i++){
         int wordlen=strlen(words[i]);
         if(wordlen < minlen){
             minlen=strlen(words[i]);
         }
     }
     for(int i=0;i<count;i++){
         if(strlen(words[i]) == minlen){
             printf("%s|",words[i]);
         }
     }
     printf("\n");
     
    return 0;
}
