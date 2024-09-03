//Program that converts time in minutes to time in hours and minutes. Use #define or const to create a symbolic constant for 60

#include<stdio.h>
#define MINUTES_IN_HOUR 60

int main()
{
	int tot_min, hours, min;

	printf("Enter time in minutes : ");
	scanf("%d",&tot_min);

	hours = tot_min / MINUTES_IN_HOUR;
	min = tot_min % MINUTES_IN_HOUR;

	printf("%d minutes is equivalent to %d hours and %d minutes\n",tot_min,hours,min);

	return 0;
}
