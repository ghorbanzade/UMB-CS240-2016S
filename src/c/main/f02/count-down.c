/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

#define START_NUM 16

int main(void)
{
	int num = START_NUM;
	while (num) {
		printf("%d ", num);
		num >>= 1;
	}
	putchar('\n');
}
