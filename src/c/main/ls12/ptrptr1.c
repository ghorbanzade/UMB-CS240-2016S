/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int main(void)
{
	int a = 1;
	int *b = &a;
	int **c = &b;
	printf("%d\n", a);   // 1
	printf("%d\n", *b);  // 1
	printf("%d\n", **c); // 1
}
