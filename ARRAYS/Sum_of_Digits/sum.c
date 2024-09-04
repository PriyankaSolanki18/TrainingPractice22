/* program that prompts the user for a positive integer and then computes the sum of all the digits of the number */

#include<stdio.h>

int main()
{
	int num;
	int tmp;
	
	printf("\nEnter a positive number : ");
	scanf("%d",&num);

	tmp=num;

	int sum=0;

	while(num)
	{
		sum = sum + (num % 10);
		num/=10;
	}

	printf("Sum of digits of %d you entered is : %d\n\n", tmp, sum);

	return 0;
}
