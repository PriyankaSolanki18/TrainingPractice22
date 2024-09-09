// program to search for a specific element in an array and print its index if found

#include<stdio.h>
#define MAX 6

int main()
{
	int arr[MAX];
	
	printf("Enter %d array elements : ",MAX);
	for(int i=0;i<MAX;i++)
	{
		scanf("%d",&arr[i]);
	}

	int key;
	printf("Enter element that is to be searched in the array : ");
	scanf("%d",&key);
	
	for(int i=0;i<MAX;i++)
	{
		if(arr[i] == key)
		printf("Element found at index : %d\n",i);
	}

	return 0;
}
