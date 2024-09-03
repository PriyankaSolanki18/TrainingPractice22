// program that reads a character from the user and checks whether it is a vowel (a, e, i, o, u) or a consonant using a switch statement

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char ch;

	printf("Enter a character to check whether it is vowel or consonant : ");
	scanf("%c",&ch);

	switch(ch){
		case 'a':
			printf("Vowel");
			break;
		case 'e':
            printf("Vowel");
			break;
		case 'i':
		    printf("Vowel");
            break;	
		case 'o':
			printf("Vowel");
			break;
		case 'u':
			printf("Vowel");
			break;
		default:
			printf("Consonant");
			break;
	}

    return EXIT_SUCCESS;
}
