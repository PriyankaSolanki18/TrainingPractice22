#include<stdio.h>

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

int main()
{
	//declare function pointer
	int (*operation[4]) (int,int);

	operation[0] = &add;
	int result = operation[0](7,8);
	printf("Sum = %d\n",result);

	operation[1] = sub;
	result = operation[1](9,2);
	printf("Sub = %d\n",result);

	operation[2] = mul;
	result = operation[2](3,6);
	printf("Mul = %d\n",result);

	operation[3] = div;
	result = operation[3](4,2);
	printf("Div = %d\n",result);
	
	return 0;
}
