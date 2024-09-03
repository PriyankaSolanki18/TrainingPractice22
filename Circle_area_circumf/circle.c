//Program to calculate area and circumference of circle

#include<stdio.h>
#include<stdlib.h>
#define PI 3.14

int main()
{
	float r;

	printf("Enter radius of circle : ");
	scanf("%f",&r);
	printf("\n");

	//Area of Circle
	printf("The area of circle of radius %f is : %f \n", r, PI*r*r);
	printf("\n");

	//Circumference of Circle
	printf("The circumference of circle of radius %f is : %f \n", r,  2*PI*r);
	printf("\n");

	return EXIT_SUCCESS;
}
