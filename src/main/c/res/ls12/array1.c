/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

int main(void)
{
	int *a[2];
	int b = 100;
	int c = 200;
	a[0] = &b;
	a[1] = &c;
	(*a[0])++;
	(*a[1])--;
	printf("b: %d, c: %d\n", b, c);
}
