#include<stdio.h>
#include<string.h>

#define MAX 5

int main()
{
	char ch[MAX];
	int len;
	printf("Enter string : ");

	if(fgets(ch,MAX,stdin) != NULL)
	{
		len = strlen(ch);
		if(ch[len-1] == '\n')
		ch[len-1] = '\0';
		
		printf("The input string is : \n");

		if(fputs(ch, stdout))
		{
			printf("error in fputs\n");
			return 2;
		}

		return 0;
	}
	else
	{
		printf("Error in fgets\n");
		return 1;
	}
}

//ERROR IN THIS CODE
