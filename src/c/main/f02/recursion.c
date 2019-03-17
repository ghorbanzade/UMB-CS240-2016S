/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
