// program to sort an array of integers in ascending order

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

	for(int i=0; i<MAX-1; i++){
		for(int j=0; j<MAX-1-i; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	printf("Printing the sorted : ");

	for(int i=0; i<MAX; i++){
		printf("%d ",arr[i]);
	}

	return 0;
}
