/* program that prompts the user for a positive integer and then reports the closest integer having a whole number square root */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int num;

	printf("Enter a positive number : ");
	scanf("%d",&num);

	int square_root = (sqrt(num));
	int lower_bound_num = square_root * square_root;
	int upper_bound_num = (square_root + 1) * (square_root +1);

	if((abs(num - lower_bound_num)) < (abs(num - upper_bound_num))){
		printf("Closest integer having a whole number square root is : %d\n\n",lower_bound_num);
	}else{
		printf("Closest integer having a whole number square root is : %d\n\n",upper_bound_num);
	}

	return 0;
}
