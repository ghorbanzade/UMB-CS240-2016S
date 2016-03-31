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
	int var1, *var2, *var3;
	var1 = 3;
	var2 = &var1;
	var3 = var2;
	(*var3)++;
	printf("value of var1: %d\n", var1);
}
