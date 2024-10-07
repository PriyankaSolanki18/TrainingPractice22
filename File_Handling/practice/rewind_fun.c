#include<stdio.h>

int main()
{
	FILE *fp;
	fp=fopen("file.txt","a");
	fprintf(fp,"Priyanka Solanki\n");
	//using rewind()
	rewind(fp);
	//reading from file
	char buffer[50];
	fscanf(fp,"%[^\n]s",buffer);
	printf("%s",buffer);
	return 0;
}
