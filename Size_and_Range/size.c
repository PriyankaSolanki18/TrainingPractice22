//Program to show size of datatypes

#include<stdio.h>

int main()
{
		int a;

		printf("char : %ld\n", sizeof(char));
		printf("short int : %ld\n", sizeof(short int));
		printf("int : %ld\n", sizeof(int));
		printf("long int : %ld\n", sizeof(long int));
		printf("long long int : %ld\n", sizeof(long long int));
		printf("float : %ld\n", sizeof(float));
		printf("double : %ld\n", sizeof(double));
		printf("long double : %ld\n", sizeof(long double));


		printf("\n\n");
		return 0;
}
