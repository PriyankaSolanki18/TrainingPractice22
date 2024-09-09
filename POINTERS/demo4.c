#include<stdio.h>


int main()
{

	int *p;
	int a[3];
	p = &a;

	printf("%u   %u   %u\n", p, a, &a);
	printf("%u   %u   %u\n", p+1, a+1, &a+1);


	return 0;

}
	


