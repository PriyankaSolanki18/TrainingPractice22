#include <stdio.h>

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
int compute(int (*operation)(int,int) ,int a, int b)
{
	return( operation(a,b) );

}

void  performOperation(char op, int a, int b)
{
	
	int result;
	switch(op)
	{
		case '+': result = compute(add, a,b); 
				  break;	
			
		case '-': result =compute(subtract,a,b); 
				  break;	
	
		case '*': result = compute(multiply,a,b); 
				  break;

		case '/': result = compute(divide,a,b); 
				  break;

		default : printf("Invalid operation\n");
	}
printf("Result = %d\n", result);
}
int main() 
{
	char op;
	int a, b;
	printf("Enter the operation\n");
	scanf("%c", &op);
	printf("Enter the operands\n");
	scanf("%d%d", &a, &b);
	performOperation(op,a,b);
	 

	return 0;
}



