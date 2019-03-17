/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
