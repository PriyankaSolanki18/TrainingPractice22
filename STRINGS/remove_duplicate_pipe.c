//Write a program that removes duplicate words from a pipe-separated string.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
#define MAXWORDS 20

int splitWords(char *str, char *words[]);
void countFrequency(char *words[], int count);

int main()
{
  char str[MAX];
  char *words[MAXWORDS];
  printf("Enter pipe seperated sequence of words\n");
  fgets(str, MAX-1, stdin);
  if(str[strlen(str)-1]=='\n')
    str[strlen(str)-1]='\0';

	int count = splitWords(str, words);
	countFrequency(words, count);
	for(int i =0; i< count; i++)
   		free(words[i]);
  	return 0;
}


void countFrequency(char *words[], int count)
{
    int visited[MAXWORDS]={0};
    for(int i = 0; i<count; i++)
    {
        if(visited[i]==1)
            continue;
        int countF = 1;
     for( int j = i+1; j < count; j++)
        {
            if(strcmp(words[i],words[j])==0)
            {
                countF++;
                visited[j]=1;
            }
        }
    printf("%s\t%d\n", words[i],countF);
    }
  }

int splitWords(char *str, char *words[])
{
    int count = 0;
    char *token = strtok(str,"|");
    while(token!=NULL)
    {
        words[count] = (char *) malloc(sizeof(token)+1);
        strcpy(words[count],token );
        count++;
        token = strtok(NULL,"|");
    }
    return count;
}
