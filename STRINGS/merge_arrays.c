// program to merge two arrays into a single array.

#include<stdio.h>

int main()
{

	int a1[5], a2[5];
	
	printf("Enter 5 elements for 1st array : ");   //INPUTTING ELEMENTS FOR a1[]
	for(int i=0; i<5; i++)
	{
		scanf("%d",&a1[i]);
	}

	printf("Enter 5 elements for 2nd array : ");   //INPUTTING ELEMENTS FOR a2[]
	for(int i=0; i<5; i++)
	{
		scanf("%d",&a2[i]);
	}

	//CREATING MERGED ARRAY

	int merged_arr[10];
	int i,j;

	for(i=0; i<5; i++){
		merged_arr[i] = a1[i];
	}
	for(j=0; j<5; j++){
		merged_arr[i+j] = a2[j];
	}

	//PRINTING MERGED ARRAYS

	printf("Merged Array : ");
	for(int i=0; i<10; i++){
		printf("%d ",merged_arr[i]);
	}printf("\n");

	return 0;
}
