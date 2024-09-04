// program to find the maximum and minimum elements in an array of integers

#include<stdio.h>
#include<limits.h>
#define MAX 10

int main()
{
	int arr[MAX];

	printf("Enter %d array elements :",MAX);
	for(int i=0; i<MAX; i++)
	{
		scanf("%d",&arr[i]);
	}

	int min_no = INT_MAX;
	int max_no = INT_MIN;

	for(int i=0; i<MAX; i++)
	{
		if(arr[i] < min_no)
		{
			min_no = arr[i];
		}
		if(arr[i] > max_no)
		{
			max_no = arr[i];
		}
	}

	printf("\nMaximum num : %d \n Minimum num : %d \n\n", max_no, min_no);

	return 0;
}
