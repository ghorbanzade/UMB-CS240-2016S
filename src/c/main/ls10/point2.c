/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

int main(void)
{
	int var1 = 3;
	int *var2;
	var2 = &var1;
	int var3 = *var2;
	printf("value of var1: %d\n", var1);
	printf("value of *var2: %d\n", *var2);
	printf("value of var3: %d\n", var3);
	printf("value of var2: %p\n", (void*) var2);
	printf("address of var1: %p\n", (void*) &var1);
	printf("address of var2: %p\n", (void*) &var2);
	printf("address of var3: %p\n", (void*) &var3);
}
