//Program to open a file, read from it and close it

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	// declare var for the data to be read from file
	char buffer[50];
	//open existing file using fopen() in "r" mode 
	fp=fopen("file.txt","r");
	if(fp==NULL){
		printf("file failed to open\n");
	}else{
		printf("file is now opened\n");
		//read buffer file using fgets()
		while(fgets(buffer,50,fp) != NULL){
			printf("%s",buffer);
		}
		//close file
		fclose(fp);
		printf("Data read succesfully from file\n");
		printf("file is now closed\n");
	}
	return 0;
}
