#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fptr;
	fptr=fopen("filename.txt","r");
	if(fptr==NULL){
		printf("The file is not opened\n");
		exit(0);
	}
	return 0;
}
