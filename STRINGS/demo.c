#include<stdio.h>
#include<string.h>

#define MAX 50

int main()
{
	char ch[MAX];

	printf("Enter string : ");

	scanf("%[^\n]s",ch);

	printf("Input string is : %s",ch);
	printf("\n");

	return 0;
}
