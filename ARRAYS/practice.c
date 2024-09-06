#include<stdio.h>
#define MAX 5

int main()
{
	int a[MAX] = {1,2,3,4,5,6,7};

	for(int i=0; i<MAX; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}
