/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include "complex-numbers.h"

/**
 * Loads complex numbers from file and prints their sum.
 */
int main(void)
{
	FILE *fp;
	float a, b;
	double complex tmp;
	double complex sum = 0;
	fp = fopen("complex-numbers.txt", "r+");
	if (fp == NULL) {
		printf("error: unable to open file.\n");
		return EXIT_FAILURE;
	}
	while (fscanf(fp, "%f, %f\n", &a, &b) != EOF) {
		tmp = a + b * I;
		sum += tmp;
	}
	cprint(sum);
	fclose(fp);
	return EXIT_SUCCESS;
}

/**
 * Prints a string representation of a complex number on standard output.
 */
void cprint(double complex num)
{
	printf("(%.2f, %.2f)\n", creal(num), cimag(num));
}
