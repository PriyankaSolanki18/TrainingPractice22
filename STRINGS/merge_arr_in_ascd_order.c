// program to merge two arrays into a single array sorted and in ascending order.

#include<stdio.h>

int main()
{
	// take input from user
	int a1[] = {7,3,1,5};
	int a2[] = {8,6,4,2};
	int n1 = sizeof(a1)/sizeof(a1[0]);
	int n2 = sizeof(a2)/sizeof(a2[0]);

	/*
	printf("Enter elements of 1st array : ");
	for(int i=0; i<n1; i++){
		scanf("%d",&a1[i]);
	}


	printf("Enter elements of 2nd array : ");
	for(int i=0; i<n2; i++){
		scanf("%d",&a1[i]);
	}
	*/

	// merge arrays
	int a3[n1+n2];
	int i,j;
	for(i=0; i<n1; i++){
		a3[i] = a1[i];
	}
	for(j=0; j<n2; j++){
		a3[i+j] = a2[j];
	}

	printf("Merged Array : ");
	for(int k=0; k<(n1+n2); k++){
		printf("%d ",a3[k]);
	}
	printf("\n");

	// sort merged array
	for(int x=0; x<(n1+n2)-1; x++){
		for(int y=0; y<(n1+n2)-1-x; y++){
			if(a3[y] > a3[y+1]){
				int tmp = a3[y];
				a3[y] = a3[y+1];
				a3[y+1] = tmp;
			}
		}
	}

	// print merged sorted array
	printf("\nMerged sorted array : ");	
	for(int k=0; k<(n1+n2); k++){
		printf("%d ",a3[k]);
	}
	printf("\n");

	return 0;
}
