#include<stdio.h>

int main()
{

	int **iptr;
	void *fptr;
	char *cptr;
	double *dptr;


	printf("Size of iptr = %d\n", sizeof(iptr));
	printf("Size of fptr = %d\n", sizeof(fptr));
	printf("Size of cptr = %d\n", sizeof(cptr));
	printf("Size of dptr = %d\n", sizeof(dptr));

	return 0;
}

