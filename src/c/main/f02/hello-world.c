/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int main(void)
{
	char *str1 = "Hello";
	char *str2 = "World!";
	str1 = str2;
	printf("%s %s\n", str1, str2);
}
