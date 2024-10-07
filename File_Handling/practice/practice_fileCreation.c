#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fptr;
	fptr=fopen("file.txt","w");

	if(fptr==NULL){
		printf("This file is not opened\n");
		exit(0);
	}else{
		printf("File created successfully\n");
	}
	return 0;
}
