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
	int a[] = {2, 3, 5, 7};
	int *b = &a[0];
	int *c = a;
	printf("value of a[2]: %d\n", a[2]);
	printf("value of a[2]: %d\n", *(b + 2));
	printf("value of a[2]: %d\n", *(c + 2));
}