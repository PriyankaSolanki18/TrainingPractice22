//Program to convert temperature from celsius to fahrenheit

#include<stdio.h>
#include<stdlib.h>

int main()
{
	float tmp;

	printf("Enter temprature in Celsius : ");
	scanf("%f",&tmp);

	//Conversion using formula Fahrenheit = (9/5) * Celsius + 32
	float result = ( (9/5) * tmp ) + 32;

	printf("\nTemperature in Fahrenheit is : %f", result);

	return EXIT_SUCCESS;
}
