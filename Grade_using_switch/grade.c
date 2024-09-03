/* program that takes a percentage input from the user and prints the corresponding grade based on the following criteria:
>= 90: Grade A
>= 80: Grade B
>= 70: Grade C
>= 60: Grade D
< 60: Fail
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int percentage;

	printf("Enter your percentage : ");
	scanf("%d",&percentage);

	switch(percentage/10)
	{
		case 10:
		case 9:
			printf("Grade A\n");
			break;
		case 8:
			printf("Grade B\n");
			break;
		case 7:
			printf("Grade C\n");
			break;
		case 6:
			printf("Grade D\n");
			break;
		default:
			printf("Fail\n");
	}

	return EXIT_SUCCESS;
}
