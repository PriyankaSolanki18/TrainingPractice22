// write a program to reverse a string or a line
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main()
{
	char str[MAX];
	printf("Enter a string/line : ");
	fgets(str,MAX,stdin);
	int len=strlen(str);
	if(str[len-1] == '\n'){
	str[len-1]='\0';
	len--;
	}

	int i=0, j=len-1;
		while(i<j)
		{
			char temp=str[i];
			str[i]=str[j];
			str[j]=temp;
			i++;
			j--;
		}
	
	printf("Reversed string is : %s\n",str);

	return 0;
}
