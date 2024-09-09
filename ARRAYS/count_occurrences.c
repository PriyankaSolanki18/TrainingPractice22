// program to count the occurrences of each element in an array

#include<stdio.h>

int main()
{
	int n;

	printf("Enter the size of array : ");
	scanf("%d",&n);

	int arr[n], freq[n];

	printf("Enter array elements : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		freq[i]=-1;
	}

	for(int i=0;i<n;i++){
	int count=1;
		for(int j=i+1;j<n;j++){
			if(arr[i] == arr[j]){
				count++;
				freq[j] = 0;
			}
		}
	if(freq[i] != 0){
		freq[i] = count;
	}
	}

	for(int i=0;i<n;i++){
	if(freq[i] != 0){
		printf("%d - %d\n ",arr[i],freq[i]);
		}
	}

	return 0;
}
