/*Program that takes a score (0-100) as input from the user and uses if statements to determine the corresponding grade:
	90-100: A
	80-89: B
	70-79: C
	60-69: D
	Below 60: F
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int score;

	printf("Enter your score from 1-100 : ");
	scanf("%d",&score);

	if(score >= 90)
		printf("Your grade is : 'A'\n");
	else if(score >= 80)
		printf("Your grade is : 'B'\n");
	else if(score >= 70)
		printf("Your grade is : 'C'\n");
	else if(score >= 60)
		printf("Your grade is : 'D'\n");
	else
		printf("Fail, Better luck next time!!!");
	
	return EXIT_SUCCESS;
}
