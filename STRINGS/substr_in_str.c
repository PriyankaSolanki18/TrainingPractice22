// WAP to get the position of a substring in a string

#include<stdio.h>
#include<string.h>

int main()
{
	char str[50], sub_str[50];
	char *pos;

	printf("Enter string : ");
	gets(str);

	printf("Enter substring : ");
	gets(sub_str);

	// finding the position

    pos = strstr(str,sub_str);

	if(pos != NULL){
		// calculate the position
		int position = pos - str;
		printf("The substring is found at position : %d \n",position);
	}else{
		printf("Substring is not found \n");
	}

	return 0;
}
