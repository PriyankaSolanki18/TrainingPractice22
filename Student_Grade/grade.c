/*  C program that performs the following tasks:
	Read an integer representing the student score.
	Read a character representing the Student Grade (A, B, C, D, or F).
	Print Your score is 90 and Grade is A
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int marks;

	printf("Enter your marks");
	scanf("%d",&marks);

	if(marks >= 90){
	printf("You enterd marks : %d and your grade is : 'A'\n",marks);
	}

	else if(marks >= 80){
    printf("You enterd marks : %d and your grade is : 'B'\n",marks);
	}

	else if(marks >= 70){
    printf("You enterd marks : %d and your grade is : 'C'\n",marks);
	}

 	else if(marks >= 60){
    printf("You enterd marks : %d and your grade is : 'D'\n",marks);
	}

	else{
    printf("You enterd marks : %d and your grade is : 'E'\n",marks);
	}

	return EXIT_SUCCESS;
}
