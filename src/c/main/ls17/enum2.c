/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

typedef enum log_level {
	DEBUG,
	INFO,
	ERROR,
	FATAL
} level;

int main(void)
{
	level a = FATAL;
	level b = DEBUG;
	level c = ERROR;
	level d = INFO;
	printf("log level is: %d\n", a); // log level is 3
	printf("log level is: %d\n", b); // log level is 0
	printf("log level is: %d\n", c); // log level is 2
	printf("log level is: %d\n", d); // log level is 1
}
