/* program that asks the user to enter the number of days and then converts that value to weeks and days. For example, it would convert 18 days to 2 weeks, 4 days. Display results in the following format: 18 days are 2 weeks, 4 days
*/

#include<stdio.h>
#define DAYS_IN_WEEKS 7
int main()
{
	int tot_days, weeks, days;
	
	printf("Enter total number of days : ");
	scanf("%d",&tot_days);

	weeks = tot_days / DAYS_IN_WEEKS;
	days = tot_days % DAYS_IN_WEEKS;

	printf("%d days are %d weeks, %d days\n\n", tot_days, weeks, days);

	return 0;
}
