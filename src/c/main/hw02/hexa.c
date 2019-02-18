/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

/**
 * this program takes the first command line argument and prints
 * hexadecimal values of its characters.
 */
int main(int argc, char *argv[])
{
	char ch;
	int i = 0;
	if (argc < 2) {
		printf("error: missing command line argument\n");
	} else {
		while ((ch = argv[1][i++]) != '\0')
			printf("%x ", ch);
		if (i != 0)
			putchar('\n');
	}
}
