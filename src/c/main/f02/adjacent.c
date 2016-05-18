/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 *
 */
int func(char *str)
{
	int i = 0;
	char ch;
	char prev = '\0';
	while ((ch = str[i++]) != '\0') {
		if (ch == prev)
			return 0;
		prev = ch;
	}
	return 1;
}

/**
 *
 */
int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("error: missing command line arguments\n");
		printf("usage: %s [string]\n", argv[0]);
		return 1;
	}
	if (func(argv[1])) {
		printf("no repetitive adjacent character\n");
	} else {
		printf("has repetitive adjacent characters\n");
	}
}
