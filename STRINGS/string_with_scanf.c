#include<stdio.h>
#define MAX 5

int main()
{
	/*
	char ch[MAX];
	printf("Enter string\n");
	scanf("%s",ch);

	printf("Input string is : %s\n",ch);
	*/

	/*
	char ch[MAX];
	printf("Enter string : ");
	scanf("%[^\n]s",ch);

	printf("Input string is : %s\n",ch);
	*/

	char ch[MAX];
	printf("Enter string : ");
	fgets(ch,MAX,stdin);

	printf("Input string is : %s\n",ch);

	return 0;
}
