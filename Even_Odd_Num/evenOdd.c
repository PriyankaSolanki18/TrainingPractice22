//Program to find given number is Odd or Even

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;

	printf("Enter a number : ");
	scanf("%d",&num);

	if(num%2 == 0)
		printf("Even Number\n");
	else
		printf("Odd Number\n");
	
	return EXIT_SUCCESS;
}
