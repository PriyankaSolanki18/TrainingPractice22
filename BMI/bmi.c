//Program that calculates the Body Mass Index (BMI) based on user input for weight (in kg) and height (in meters). (Formula bmi =weight/(height * height)

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int height;
	int weight;

	printf("Enter height : ");
	scanf("%d",&height);

	printf("Enter weight : ");
	scanf("%d", &weight);

	int bmi = weight / (height * height);

	printf("The BMI is : %d", bmi);

	return EXIT_SUCCESS;
}
