/*
9. Sort Words Alphabetically: Write a program that sorts the words in a pipe-separated string alphabetically. For example, for input: apple|banana|grape|orange, the output should be apple|banana|grape|orange.
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
    
    int count=0;
    char *token=strtok(str,"|");
    while(token != NULL){
        words[count]=token;
        count++;
        token=strtok(NULL,"|");
    }
    
    //check
    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-i-1;j++){
            if(strcmp(words[j],words[j+1]) > 0){
                char * temp = words[j];
                words[j]=words[j+1];
                words[j+1]=temp;
            }
        }
    }
   
     // Print results
    printf("After sorting alphabatically:\n");
    for (int i = 0; i < count; i++) {
        if (i > 0) { // Print only words that are counted
            printf("|");
        }
        printf("%s",words[i]);
    }
    printf("\n");
    
    return 0;
}
