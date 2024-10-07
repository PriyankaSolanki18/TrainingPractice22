#include<stdio.h>

typedef int(*operation)(int,int);

//function definition
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
	if(b != 0)
		return a/b;
	else
		return 0;
}

operation getOperation(char op)
{
	int result;
	switch(op)
	{
		case '+': return add;
				  break;
		case '-': return sub;
		          break;
	    case '*': return mul;
				  break;
		case '/': return div;
				  break;
		default: printf("Invalid operation\n");
	}
}

int main()
{
	char op;
	int a,b;
	printf("Enter operation : ");
	scanf("%c",&op);
	printf("Enter operands : ");
	scanf("%d %d",&a,&b);
	operation fun = getOperation(op);
	printf("Result = %d\n",fun(a,b));
	return 0;
}
