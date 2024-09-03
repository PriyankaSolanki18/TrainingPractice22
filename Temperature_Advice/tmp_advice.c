/* program that takes a temperature value as input and uses if statements to print advice based on the temperature:
Above 30: "It's hot outside, stay hydrated!"
Between 20 and 30: "The weather is nice and warm."
Between 10 and 19: "It's a bit chilly, wear a jacket."
Below 10: "It's cold outside, stay warm!"
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int tmp;

	printf("Enter temperature in Celsius : ");
	scanf("%d",&tmp);

	if(tmp > 30)
		printf("It's hot outside, stay hydrated!\n");
	else if(tmp >=20 && tmp <= 30)
		printf("The weather is nice and warm.\n");
	else if(tmp >=10 && tmp < 20)
		printf("It's a bit chilly, wear a jacket.\n");
	else
		printf("It's cold outside, stay warm!\n");
	
	return EXIT_SUCCESS;
}
