// Write a program to remove duplicate elements from an array.

#include<stdio.h>

int main()
{
	int n;
	printf("Enter size of arr : ");
	scanf("%d",&n);

	int arr[n];
	printf("Enter arr elements : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i] == arr[j]){
				for(int k=j;k<n;k++){
					arr[k] = arr[k+1];
				}
				j--;
				n--;
			}
		}
	}

	printf("Array after removing duplicate elements : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

	return 0;
}
