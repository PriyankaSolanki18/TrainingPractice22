// program to initialize an array with the first 10 natural numbers and print the elements

#include<stdio.h>

int main()
{
	//defining an arr with 10 elements
	int arr[10];

	//initializing an arr with first 10 natural numbers
	for(int i=0;i<10;i++)
	{
		arr[i] = i+1;
	}

	//printing the elements
	printf("First 10 natural numbers are : \n");
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
