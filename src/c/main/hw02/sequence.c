/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

/**
 * this program all numbers in form of 2^i-1 where 1 <= i <= 16
 * without using the multiply operator.
 */
int main(int argc, char *argv[])
{
	int i;
	unsigned long int num = 0;
	for (i = 0; i <= 64; i++) {
		printf("%lu ", num);
		num = num << 1;
		num = num | 1;
	}
	putchar('\n');
}
