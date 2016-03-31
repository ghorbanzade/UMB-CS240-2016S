/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

void function1()
{
	printf("first function\n");
}

void function2()
{
	printf("second function\n");
}

int wrapper(void (*func)(void))
{
	(*func)();
}

int main(void)
{
	wrapper(&function1);
	wrapper(&function2);
}
