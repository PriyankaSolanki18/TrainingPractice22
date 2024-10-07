#include<stdio.h>

int main()
{
	FILE *fp;
	fp=fopen("file.txt","r");
	//moving pointer to end
	fseek(fp,0,SEEK_END);
	//printing position of pointer
	printf("%ld\n",ftell(fp));
	return 0;
}
