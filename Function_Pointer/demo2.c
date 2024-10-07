#include<stdio.h>

//function definitions
int add(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
	return a-b;
}
int mul(int a, int b)
{
	return a*b;
}
int div(int a, int b)
{
	if(b!=0)
		return a/b;
	else
		return 0;
}

int compute(int (*operation)(int,int), int a, int b)
{
	return (operation(a,b));
}
void performOperation(char op, int a, int b)
{
	int result;
	switch(op)
	{
		case '+' : result = compute(add,a,b);
				   break;
		case '-' : result = compute(sub,a,b);
		           break;
	    case '*' : result = compute(mul,a,b);
		           break;
	    case '/' : result = compute(div,a,b);
				   break;
	    default : printf("Invalid operation\n");
	}
	printf("Result = %d\n",result);
}

int main()
{
	char op;
	int a,b;
	printf("Enter operation (+,-,*,/) : ");
	scanf("%c",&op);
	printf("Enter operands : ");
	scanf("%d %d",&a,&b);
	performOperation(op,a,b);
	return 0;
}
