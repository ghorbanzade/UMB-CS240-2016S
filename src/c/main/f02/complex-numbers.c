/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
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
