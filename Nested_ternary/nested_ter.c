//Program to find the maximum of three numbers using nested ternary operators

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n1;
	int n2;
	int n3;

	printf("Enter 3 numbers : ");
	scanf("%d %d %d", &n1, &n2, &n3);

	int max = (n1>n2) ? ((n1>n3) ? n1 : n2) : ((n2>n3) ? n2 : n3);

	printf("Largest among %d, %d and %d is : %d", n1,n2,n3,max);

	return EXIT_SUCCESS;
}
