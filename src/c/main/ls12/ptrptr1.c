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
	int a = 1;
	int *b = &a;
	int **c = &b;
	printf("%d\n", a);   // 1
	printf("%d\n", *b);  // 1
	printf("%d\n", **c); // 1
}