/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc >= 2) {
		printf("%s is %s today!\n", argv[1], argv[2]);
	} else {
		printf("Error: insufficient number of arguments\n");
	}
}
