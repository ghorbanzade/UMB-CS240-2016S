/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>

enum log_level {
	DEBUG,
	INFO,
	ERROR,
	FATAL
};

int main(void)
{
	enum log_level a = FATAL;
	enum log_level b = DEBUG;
	enum log_level c = ERROR;
	enum log_level d = INFO;
	printf("log level is: %d\n", a); // log level is 3
	printf("log level is: %d\n", b); // log level is 0
	printf("log level is: %d\n", c); // log level is 2
	printf("log level is: %d\n", d); // log level is 1
}
