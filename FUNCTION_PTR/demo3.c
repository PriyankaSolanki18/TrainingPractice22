
#include <stdio.h>

typedef int (*operation) (int , int);

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0)
        return a / b;
    else
        return 0;
}
 operation  getOperation(char op)
{
	
//		int result;
	switch(op)
	{
		case '+': return add; 
				  break;	
			
		case '-': return subtract;
				  break;	
	
		case '*': return multiply;
				  break;

		case '/': return divide;
				  break;

		default : printf("Invalid operation\n");
	}
}
int main() 
{
	char op;
	int a, b;
	printf("Enter the operation\n");
	scanf("%c", &op);
	printf("Enter the operands\n");
	scanf("%d%d", &a, &b);
	operation fun = getOperation(op);
	printf("Result = %d\n", fun(a,b));

	return 0;
}



