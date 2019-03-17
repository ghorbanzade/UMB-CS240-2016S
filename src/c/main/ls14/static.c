/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>

void increment_var(void);

static int var = 0;

int main(void)
{
	var = 4;
	increment_var();
	printf("value of var: %d\n", var);
}

void increment_var(void)
{
	var++;
}
