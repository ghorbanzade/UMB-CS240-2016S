/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[10] = "Goodbye";
	printf("%s ", string);
	string[4] = '\0';
	printf("%s\n", string);
}
