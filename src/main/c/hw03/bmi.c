/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

/**
 * print the group under which the person is classified
 * based on his given bmi
 */
void classify(float bmi)
{
	printf("You are classified as ");
	if (bmi < 18.5)
		printf("Underweight");
	else if (bmi < 24.9)
		printf("Normal");
	else if (bmi < 29.9)
		printf("Overweight");
	else
		printf("Obses");
	printf(".\n");
}

/**
 * This program takes height in inch and weight in pound 
 * and prints his bmi as well as the group under which
 * he is classified.
 */
int main(void)
{
	int height, weight;
	float bmi;
	printf("Your height (in): ");
	scanf("%d", &height);
	printf("Your weight (lb): ");
	scanf("%d", &weight);
	bmi = weight * 703.0 / height / height;
	printf("Your BMI is %.2f\n", bmi);
	classify(bmi);
}
