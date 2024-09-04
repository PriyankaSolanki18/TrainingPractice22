// program to read and print array elements( using index and using address)

#include<stdio.h>
#define MAX 5

int main()
{
	int arr[MAX];

	printf("\nEnter %d array elements : ",MAX);
	for(int i=0; i<MAX; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("\nPRINTING ARR ELEMENTS USING INDEX\n");
	for(int i=0; i<MAX; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");

	printf("\nPRINTING ARR ELEMENTS USING ADDRESS\n");
      for(int i=0; i<MAX; i++)
      {
          printf("%d ",*(arr + i));
      }
	 printf("\n\n");

	return 0;
}
