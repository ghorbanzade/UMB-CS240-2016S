/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%d: %s\n", argc, *++argv);
}
