#include<stdio.h>
#define ROW 3
#define COL 3

int main()
{
	int a[ROW][COL] ={{1,2,3},{4,5,6},{7,8}};

	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
