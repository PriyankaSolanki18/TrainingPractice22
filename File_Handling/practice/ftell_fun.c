#include<stdio.h>

int main()
{
	FILE *fp=fopen("file.txt","r");
	if(fp == NULL)
	{
		printf("Failed to open the file\n");
		return 1;
	}
	char str[20];
	fscanf(fp,"%s",str);
	printf("%ld\n",ftell(fp));
	fclose(fp);
	return 0;
}
