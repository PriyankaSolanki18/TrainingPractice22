/*

Write a C program to replace first occurrence of a character with another character in a string.

Example

Input

Input string: I love programming.

Input character to replace: .

Input character to replace with: !

Output

String after replacing '.' with '!': I love programming!

*/

#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#define MAX 30
 
int main()

{

    char* str = NULL;

    char ch1;

    char ch2;

    str=(char *)malloc(MAX*sizeof(str));

    if(str == NULL){

        printf("malloc failed");

        free(str);

        return EXIT_FAILURE;

    }

    printf("Enter a string : ");

    if(fgets(str,MAX,stdin) == NULL){

        printf("fgets failed");

        free(str);

        return EXIT_FAILURE;

    }

    int len=strlen(str);

    if(len>0 && str[len-1]=='\n'){

        str[len-1]='\0';

        len--;

    }

    printf("Input character to replace : ");

    scanf("%c",&ch1);

    while(getchar()!='\n');

    printf("Input character to replace with : ");

    scanf("%c",&ch2);

    int start=0, first_occr=-1;

    while(start<len){

        if(str[start] == ch1){

            first_occr = start;

            break;

        }

        start++;

    }

    str[first_occr] = ch2;

    //print output

        printf("%s",str);

    free(str);

    return EXIT_SUCCESS;

}
 
