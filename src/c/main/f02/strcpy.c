/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>

void func(char *s, char *t)
{
	while ((*s++ = *t++));
}

int main(void)
{
	char a[10] = "Hello";
	char b[10];
	func(b, a);
	printf("b: %s\n", b);
}
