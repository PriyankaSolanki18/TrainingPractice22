// Find Longest Word: Write a program that finds and prints the longest word from a pipe-separated string. For example, for input apple|banana|grape|orange, the output should be banana (if there are multiple longest words, you can print all of them).

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
int main() {
    char str[MAX];
    char *words[MAX];
    
    printf("Enter string : ");
    fgets(str,MAX-1,stdin);
    int len=strlen(str);
    if(str[len-1] == '\n')
    str[len-1] = '\0';
    
    int count=0;
    char *token=strtok(str,"|");
    while(token != NULL){
    words[count]=token;
    count++;
   token=strtok(NULL,"|");
}
   int maxlen=0;
   for(int i=0;i<count;i++){
       int wordlen=strlen(words[i]);
       if(wordlen > maxlen)
       maxlen=wordlen;
   }
    
    printf("Longest words : ");
    for(int i=0;i<count;i++){
        if(strlen(words[i]) == maxlen){
        if(i>0)
        printf("|");
        printf("%s",words[i]);
        }
    }
    printf("\n");
    
    return 0;
}
