/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

void increment(int var);

int main(void)
{
	int var = 4;
	increment(var);
	printf("value of var: %d\n", var);
}

void increment(int var)
{
	var++;
}
