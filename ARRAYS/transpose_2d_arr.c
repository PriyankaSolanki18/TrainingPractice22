// Write a program to find the transpose of a given 2D array

#include<stdio.h>

int main()
{
	int row, col;
	printf("Enter number of rows : ");
	scanf("%d",&row);
	printf("Enter number od columns : ");
	scanf("%d",&col);

	int a[row][col];
	int b[col][row];

	printf("Enter array elements : \n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%d",&a[i][j]);
		}
	}

	// tranposing 2d array

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			b[i][j] = a[j][i];
		}
	}

	//printfng transposed arr

	printf("Transposed array : \n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}

	return 0;
}
