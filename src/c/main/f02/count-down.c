/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

#define START_NUM 16

int main(void)
{
	int num = START_NUM;
	while (num) {
		printf("%d ", num);
		num >>= 1;
	}
	putchar('\n');
}
