/* program to determine whether a given positive integer is an Armstrong number. An Armstrong number (also known as a narcissistic number or pluperfect number) is a number that is equal to the sum of its own digits each raised to the power of the number of digits
Your program should:
i. Prompt the user to enter a positive integer.
ii. Determine the number of digits in the number.
iii. Calculate the sum of each digit raised to the power of the total number of digits.
iv Compare the calculated sum to the original number to determine if it is an Armstrong number.
v. Print "Armstrong number" if the number is an Armstrong number, otherwise print "Not an Armstrong number".
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int num, tmp, org_num, sum=0, r;
	//1.
	printf("\nEnter a positive  number : ");
	scanf("%d",&num);
	
	org_num = num;
	tmp = num;

	//2. Digits
	int count_digits=0;
	while(num)
	{
		count_digits++;
		num /= 10;
	}

	//3. Sum of each digit raised to the power of the total number of digits
	while(tmp)
	{
		r = tmp % 10;
		sum += pow(r,count_digits);
		tmp /= 10;
	}
	printf("\nSum of each digit raised to the power of the total number of digits is : %d",sum);

	//4. and 5.
	if(sum == org_num)
		printf("\nArmstrong Number\n\n");
	else
		printf("\nNot Armstrong Number\n\n");
	
	return 0;
}
