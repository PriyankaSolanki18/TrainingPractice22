#include<stdio.h>

int main()
{
	
	int a = 5;
	int *iptr;
	int **dptr;

	iptr = &a;

	dptr = &iptr;

	printf("Using variable a\n");
	printf("The value of a %d\n", a);
	printf("The adddress of a %u\n", &a);
//	printf("The value of *a  %u\n", *a); invalid


	printf("Using iptr\n");
	printf("The value of a %d\n", *iptr);
	printf("The adddress of a %u\n", iptr);
	printf("The address of &iptr  %u\n", &iptr);


	printf("Using dptr\n");
	printf("The value of a %d\n", **dptr);
	printf("The calue of iptr %u\n", *dptr);
	printf("The value of dptr  %u\n", dptr);
	printf("The  address of &dptr %u\n", &dptr);

	return 0;

}

