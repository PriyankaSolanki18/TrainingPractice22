#include<stdio.h>


int main()
{

	void *iptr;

/*	int a = 10;
	float b =12.5;

	ptr = &a;
	printf("The address of a %u\n", ptr);
	printf("The value of a %u\n", *((int *)ptr));
	

	ptr = &b;
	*ptr = 34.5;
	*((float *)ptr) = 13.4;
	printf("b= %f\n", b); */


	int a[5];
	//int * iptr;
	iptr = a;
	int i;
	for (i= 0; i< 5; i++)
		scanf("%d", iptr+i);
	
	printf("The first eletmen %d\n", *((int *)iptr));
	printf("The address of first eletmen %d\n", iptr);
    iptr++;
	printf("The second element %d\n", *((int*)iptr));
	printf("The  address of second element %d\n", iptr);
	
//	a++; //invalid

	return 0;
}

