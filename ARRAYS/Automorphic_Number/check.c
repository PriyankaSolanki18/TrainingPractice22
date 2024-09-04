/* program to check if a number is an automorphic number (a number whose square ends in the same digits as the number itself).
Example:
Consider the number 76.
1. Calculate the square of the number:
      76*76=5776
2. Determine the number of digits in the original number:
	Number of digits in 76 is 2.
3. Therefore extract the last 2 digits from the square: (mod of 10 to the power 2)
       5776 mod 100 = 76
4. Compare the extracted digits with the original number:
	Extracted digits: 76
	Original number: 76
Since the extracted digits (76) match the original number (76), 76 is an automorphic number
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int num;

	printf("\nEnter a number : ");
	scanf("%d",&num);
	
	// tmp is for checking last digits with the number entered by user is equivalent or not
	int tmp = num;

	int square = num * num;

	// calculating the number of digits in original number
	int count_digits=0;
	while(num)
	{
		count_digits++;
		num/=10;
	}

	int lst_digits = (square % (int)(pow(10,count_digits)));
	
	if(lst_digits == tmp)
		printf("\n%d is an Automorphic number\n\n",tmp);
	else
		printf("\n%d is not an Automorphic number\n\n",tmp);

	return 0;
}
