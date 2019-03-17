/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>

void say_hello(int i)
{
	printf("Hello!\n");
	if (--i > 0)
		say_hello(i);
}

int main(void)
{
	say_hello(10);
}
