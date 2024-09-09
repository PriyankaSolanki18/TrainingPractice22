// program to check if an array is a palindrome.

#include<stdio.h>

int main()
{
	int n;
	printf("Enter size of arr : ");
	scanf("%d",&n);

	int arr[n];
	printf("Enter array elements : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int flag=0;

	// checking if arr is palindrome
	for(int i=0; i<n/2; i++){
		if(arr[i] == arr[n-1-i])
			flag = 1;	
	}

	if(flag == 1){
		printf("Array is palindrome\n");
	}
	else{
		printf("Array is not palindrome\n");
	}

	return  0;
}
