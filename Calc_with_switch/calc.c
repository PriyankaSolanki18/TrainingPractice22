/* Program that simulates a simple calculator using a switch statement. The user should input two numbers and an operator (+, -, *, /) and the program should print the result
*/

#include<stdio.h>

int main()
{
	char op;
	int n1, n2;
	
	printf("Enter an operator(+, -, *, /) : ");
	scanf("%c",&op);

	printf("Enter 2 numbers : ");
	scanf("%d %d", &n1, &n2);

	switch(op)
	{
		case '+':
			printf("Addition : %d\n", n1+n2);
			break;
		case '-':
			printf("Subtraction : %d\n", n1-n2);
			break;
		case '*':
			printf("Multiplication : %d\n", n1*n2);
			break;
		case '/':
			printf("Division : %d\n", n1/n2);
			break;
		default:
		 printf("Wrong operator\n");
	}

	return 0;
}
