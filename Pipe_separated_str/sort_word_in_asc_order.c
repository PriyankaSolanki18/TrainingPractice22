/*
3. Write a program that sorts the words by their length in ascending order in a pipe-separated string.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define MAXWORDS 50

int splitWords(char *str, char *words[]);
void sortAscd(char *words[],int count);

int main()
{
    char str[MAX];
    char *words[MAXWORDS];
    
    printf("Enter pipe-separated string : ");
    fgets(str,MAX-1,stdin);
    int len=strlen(str);
    if(str[len-1]=='\n')
    str[len-1]='\0';
    
    int count = splitWords(str,words);
    sortAscd(words,count);
    
    printf("Words sorted by their length in ascending order : \n");
    for(int i=0;i<count;i++)
    {
        printf("%s \n",words[i]);
    }
    printf("\n");
    
    for(int i=-0;i<count;i++){
        free(words[i]);
    }

    return 0;
}
int splitWords(char *str, char *words[])
{
    int count=0;
    char *token=strtok(str,"|");
    while(token != NULL){
        words[count]=token;
        count++;
        token=strtok(NULL,"|");
    }
    return count;
}
void sortAscd(char *words[],int count)
{
    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-1-i;j++){
            if(strlen(words[j]) > strlen(words[j+1])){
                char *temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
    return;
}
