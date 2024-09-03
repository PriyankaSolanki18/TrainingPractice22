//Program that uses the ternary operator (?:) to find the maximum of two numbers

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n1;
	int n2;
	
	printf("Enter 2 numbers : ");
	scanf("%d %d", &n1, &n2);

	(n1>n2) ? printf("\n%d is greater\n", n1) : printf("\n%d is greater\n", n2);

	return EXIT_SUCCESS;
}
