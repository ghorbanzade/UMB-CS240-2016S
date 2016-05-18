/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

int function1(float a, float b)
{
	return (a <= b) ? 0 : 1;
}

int function2(float a, float b)
{
	return (a < b) ? 1 : 0;
}

void compare(float num1, float num2, int (*func)(float, float))
{
	printf("%d\n", (*func)(num1, num2));
}

int main(void)
{
	compare(2.5, 5.2, &function1); // 0
	compare(2.5, 5.2, &function2); // 1
}
