/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

#define MIN 60
#define MAX 100
#define STEP 10

int main(void)
{
	int tempC, tempF;
	printf(" %-4s %-4s \n", "C", "F");
	printf("-----------\n");
	for (tempC = MIN; tempC <= MAX; tempC += STEP) {
		tempF = tempC * 9 / 5 + 32;
		printf(" %-4d %-4d\n", tempC, tempF);
	}
}
