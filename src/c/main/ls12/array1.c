/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int main(void)
{
	int *a[2];
	int b = 100;
	int c = 200;
	a[0] = &b;
	a[1] = &c;
	(*a[0])++;
	(*a[1])--;
	printf("b: %d, c: %d\n", b, c);
}
