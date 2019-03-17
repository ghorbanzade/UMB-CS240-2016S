/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>

int main(void)
{
	int var1, *var2, *var3;
	var1 = 3;
	var2 = &var1;
	var3 = var2;
	(*var3)++;
	printf("value of var1: %d\n", var1);
}
