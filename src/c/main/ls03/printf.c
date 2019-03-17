/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...)
{
	va_list arg;
	int done;
	va_start(arg, format);
	done = vfprintf(stdout, format, arg);
	va_end(arg);
	return done;
}

int main(void)
{
	my_printf("hello %d!\n", 15);
}
