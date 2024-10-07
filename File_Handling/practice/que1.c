// Program to create a file, write in it and close the file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//Declare a file pointer
	FILE *fp;
	//get data to be written in file
	char str[50]="This is the first created file";
	//open existing file using fopen() in "w" mode 
	fp=fopen("file.txt","w");
	if(fp==NULL){
		printf("file failed to open\n");
	}else{
		printf("The file is now opened\n");
		//write data that is to be written in the opened file
		if(strlen(str)>0){
			fputs(str,fp);
			fputs("\n",fp);
	}
	//close the file
	fclose(fp);
	printf("Data successfully written in file\n");
	printf("File is now closed\n");
	}
	return 0;
}
