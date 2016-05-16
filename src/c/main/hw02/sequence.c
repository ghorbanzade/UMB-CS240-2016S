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
 * this program all numbers in form of 2^i-1 where 1 <= i <= 16
 * without using the multiply operator.
 */
int main(int argc, char *argv[])
{
	int i;
	unsigned long int num = 0;
	for (i = 0; i <= 64; i++) {
		printf("%lu ", num);
		num = num << 1;
		num = num | 1;
	}
	putchar('\n');
}
