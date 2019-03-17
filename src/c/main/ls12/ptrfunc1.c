/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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

void wrapper(void (*func)(void))
{
	(*func)();
}

int main(void)
{
	wrapper(&function1);
	wrapper(&function2);
}
