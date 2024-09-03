/* BMI program and Use if statements to classify the BMI into categories:
Below 18.5: Underweight
18.5 to 24.9: Normal weight
25 to 29.9: Overweight
30 and above: Obesity
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	float h, w;

	printf("Enter your height and weight : ");
	scanf("%f %f", &h, &w);

	float bmi = w / (h * h);

	if(bmi >= 30)
		printf("Obesity\n");
	else if(bmi >= 25 && bmi <= 29.9)
		printf("Overweight\n");
	else if(bmi >= 18.5 && bmi <= 24.9)
		printf("Normal Weight\n");
	else
		printf("Underweight\n");
	
	return EXIT_SUCCESS;
}
