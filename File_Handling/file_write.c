#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	FILE *fp;
	int ret_val=0;

	fp = fopen("test.txt","w");
	if(fp == NULL)
	{
		printf("Error in file open\n");
		exit(1);
	}
	printf("Enter num : ");
	scanf("%d",&num);
	
	ret_val = fprintf(fp,"%d",num);
//	ret_val = fprintf(fp,"The number is: %d\n",num);
	if(ret_val <= 0)
	{
		ret_val = fclose(fp);
		printf("Write Failed\n");
		return EXIT_FAILURE;
	}
	ret_val=fclose(fp);
	if(ret_val != 0)
	{
		printf("Closing the file failed\n");
		return EXIT_FAILURE;
	}
	return 0;
}
