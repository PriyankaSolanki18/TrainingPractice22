//Program for different arithmentic operartors

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a;
	int b;

	printf("Enter first integer : ");
	scanf("%d",&a);

	printf("Enter second integer : ");
	scanf("%d", &b);

	//Addition
	printf("The addition of %d and %d is : %d\n", a, b, a+b);

	//Subtraction
	printf("The subtraction of %d and %d is : %d\n",  a, b, a-b);

	//Multiplication
	printf("The multiplication of %d and %d is : %d\n", a, b, a*b);

	//Division
	printf("The division of %d and %d is : %d\n", a, b, a/b);

	//Modulo
	printf("The mudulo of %d and %d is : %d\n", a, b, a%b);

	return EXIT_SUCCESS;
}
