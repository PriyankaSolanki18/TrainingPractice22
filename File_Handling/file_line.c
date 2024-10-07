/*
This program writes a few strings to a file, then reads those strings back from the file and prints them to the console, along with their lengths.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
#define SIZE 3

int main()
{
	FILE *infile=NULL;
	char *input[SIZE] = {"PRISM\n", "Nalanda\n", "Aricent\n"};
	char output[MAX];
	int fputs_ret=0; // return value from fputs
	int fclose_ret=0; // return value from fclose
	int index=0; // for loop index
	char *temp; //temporary variable to store the return value of the fgets function, which reads strings from a file.
	
	memset(output,0,MAX); // initializing the array
	
	//writing in the file
	infile = fopen("sample1","w");
	if(infile == NULL)
	{
		printf("File can't be open\n");
		return 0;
	}

	for(index=0; index<SIZE; index+=1)
	{
		fputs_ret = fputs(input[index], infile);
		if(fputs_ret == EOF)
		{
			printf("Error in fputs\n");
			fclose_ret = fclose(infile);
			if(fclose_ret != 0)
			{
				printf("Error in fclose\n");
				return 0;
			}
			return 0;
		}
	}

	fclose_ret = fclose(infile);
	if(fclose_ret != 0)
	{
		printf("Error in fclose\n");
		return 0;
	}

	//opening the file in "r" mode
	infile = fopen("sample1","r");
	if(infile == NULL)
	{
		printf("File can't be opened\n");
		return 0;
	}

	while(!feof(infile))
	{
		temp = fgets(output,MAX,infile);
		if(temp != NULL)
		{
			int len = strlen(output);
			if(output[len-1] == '\n')
				output[len-1] = '\0';
				printf("%s\n",output);
				printf("%d\n",strlen(output));
		}
	}

	fclose_ret = fclose(infile);
	if(fclose_ret != 0)
	{
		printf("Error in fclose\n");
		return 0;
	}

	return 0;
}
