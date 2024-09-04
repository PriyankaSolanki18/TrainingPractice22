// program to calculate the sum and average of elements in an array

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

	int sum = 0;
	int avg;

	//sum calculation
	for(int i=0;i<MAX;i++)
	{
		sum += arr[i];
	}

	//avg calculations
	int size = sizeof(arr)/sizeof(int);
	
	avg = sum/size;

	//printing output
	printf("\n Sum : %d\nAverage : %d\n", sum, avg);

	return 0;
}
