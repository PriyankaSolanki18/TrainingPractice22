#include<stdio.h>

//function definition

int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int mul(int a, int b){
	return a*b;
}

int div(int a, int b){
	if(b != 0)
		return a/b;
	else
		return 0;
}

int main()
{
	//declare function pointer
	int (*operations[2])(int,int);

	operations[0]=&add;

	int result = operations[0](4,5);

	printf("Add : %d\n",result);

	operations[0]=sub;

	result = operations[0](9,5);

	printf("Subtract : %d\n",result);

	return 0;
}
