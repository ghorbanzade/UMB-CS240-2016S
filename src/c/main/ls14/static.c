/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

void increment_var(void);

static int var = 0;

int main(void)
{
	var = 4;
	increment_var();
	printf("value of var: %d\n", var);
}

void increment_var(void)
{
	var++;
}
