/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "ls09-header.h"

int main(void)
{
	say_hello(NUM_TIMES);
}

void say_hello(int i)
{
	printf("Hello!\n");
	if (--i > 0)
		say_hello(i);
}
