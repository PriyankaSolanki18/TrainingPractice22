/*This is a program for calculating sum of 2 numbers
	OWNER : Priyanka Solanki DATE : 03-09-2024
	REVISION HISTORY : 
		OWNER : DATE : REASON : 
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	int b;
	int ret_val;
	
	printf("Enter number 1 : ");
	scanf("%d",&a);
	printf("Enter number 2 : ");
	scanf("%d",&b);
	ret_val=printf("The sum of %d and %d is %d\n", a, b, a+b);
	printf("Number of characters printed : %d\n", ret_val);


	//To handle printf error
	if(ret_val < 0){
		return EXIT_FAILURE;
		printf("Error while printing\n");
	}
		return EXIT_SUCCESS;
		printf("Success\n");
}
