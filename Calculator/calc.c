/* program that simulates a simple calculator using a switch statement. The user should input two numbers and an operator (+, -, *, /) and the program should print the result.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n1,n2;

	printf("Enter 2 numbers : ");
	scanf("%d %d", &n1, &n2);

	printf("--------OPTIONS YOU CAN CHOOSE FROM--------\n");
	printf(" 1. + \n 2. - \n 3. * \n 4. / \n");
	printf("-------------------------------------------\n");

	char ch;

	printf("Enter an option from above menu : ");
	scanf("%c", &ch);

	switch(ch)
	{
		case '+':
			printf("Addition of %d and %d is : %d\n", n1,n2,n1+n2);
			break;
		case '-':
			printf("Subtraction of %d and %d is : %d\n", n1,n2,n1-n2);
			break;
		case '*':
			printf("Multiplication of %d and %d is : %d\n", n1,n2,n1*n2);
			break;
		case '/':
			printf("Division of %d and %d is : %d\n", n1,n2,n1/n2);
			break;
		default:
			printf("Please enter correct option and Try again\n");
			break;
	}

	return EXIT_SUCCESS;
}
