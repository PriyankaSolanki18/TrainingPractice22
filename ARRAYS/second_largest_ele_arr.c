// program to find the second largest element in an array.

#include<stdio.h>

int main()
{
	int n;
	printf("Enter size of arr : ");
	scanf("%d",&n);

	int arr[n];
	printf("Enter array elemnts : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	// sort the arr in ascending order 

	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n-1-i;j++){
			if(arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}

	printf("Sorted array : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	//finding 2nd largest element array

	printf("2nd largest elemnent is : %d",arr[n-2]);
	printf("\n");

	return 0;
}
