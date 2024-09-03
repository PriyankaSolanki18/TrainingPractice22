// program that takes an integer input from the user and prints whether it is positive, negative, or zero.

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;

	printf("Enter a number : ");
	scanf("%d",&num);

	if(num > 0)
		printf("Positive number\n");
	else if(num < 0)
		printf("Negative number\n");
	else
		printf("Zero\n");
	
	return EXIT_SUCCESS;
}
