// 2 D Array

#include<stdio.h>
#define ROW 3 
#define COL 3

int main()
{
	int arr[ROW][COL];

	printf("Enter 2 d array elements : ");
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			scanf("%d",&arr[i][j]);
			}
		}
	
	printf("\nThe 2 d array elements are :\n");
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			printf("%d ",arr[i][j]);
        	}
			printf("\n");
        }

	return 0;
}
