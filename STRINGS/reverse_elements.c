// program to reverse the elements of an array

#include<stdio.h>
#define MAX 10

int main()
{
	int arr[MAX];
	
	printf("Enter %d array elements : ",MAX);

	for(int i=0;i<MAX;i++)
	{
		scanf("%d",&arr[i]);
	}

	//creating a reverse array
	int rev_arr[MAX];
	int j=0;
	
	for(int i=MAX-1;i>=0;i--)
	{
		rev_arr[j] = arr[i];
		j++;
	}

	//printing reversed array
	printf("Reversed array elements are : ");
	for(int i=0;i<MAX;i++)
	{
	printf("%d ",rev_arr[i]);
	}

	return 0;
}
