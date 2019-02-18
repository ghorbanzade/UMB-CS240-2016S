/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

#define MAX 5

void func(int num)
{
	if (++num < MAX)
		func(num);
	printf("%d ", num);
}

int main(void)
{
	func(0);
	putchar('\n');
}
