/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc >= 2) {
		printf("Hello %s!\n", argv[1]);
	} else {
		printf("Hello!\n");
	}
}
