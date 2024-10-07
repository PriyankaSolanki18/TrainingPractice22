#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	int ret_val=0;
	FILE *fp;

	if((fp = fopen("test.txt","r")) == NULL)
	{
		printf("Error in opening file\n");
		//program exists if the fp return NULL
		exit(1);
	}

	ret_val = fscanf(fp,"%d",&num);
	if(ret_val == EOF)
	{
		printf("Read Failed\n");
		return EXIT_FAILURE;
	}
	printf("The number is: %d\n",num);
	ret_val = fclose(fp);
	if(ret_val != 0)
	{
		printf("Closing the file failed\n");
		return 0;
	}
	return 0;
}
