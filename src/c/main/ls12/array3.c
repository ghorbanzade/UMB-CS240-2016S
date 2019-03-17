/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int main(void)
{
	char *a[] = {"Hello", "world!"};
	printf("%s\n", a[0]);    // Hello
	printf("%s\n", a[1]);    // world!
	printf("%c\n", a[0][4]); // o
	printf("%c\n", a[1][2]); // r
}
