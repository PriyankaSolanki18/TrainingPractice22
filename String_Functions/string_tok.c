#include<stdio.h>
#include<string.h>


#define MAX 32


int main()
{

	char str[MAX];
	char *token;
	memset(str, 0, MAX);

	printf("Enter any string\n");
	fgets(str, MAX, stdin);

	if(str[strlen(str)-1] == '\n')
		str[strlen(str)-1] = '\0';
	token = strtok(str, "|.");
	while(token != NULL)
	{
		puts(token);
		token = strtok(NULL, "|.");
	}

	printf("The input string is ");
	fputs(str, stdout);

	printf("\n\n");
	return 0;
}

