/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#include <ctype.h>

/**
 * this program takes an arbitrary number of command line arguments
 * and prints them all in uppercase characters.
 */
int main(int argc, char *argv[])
{
	int i;
	int j;
	char ch;
	if (argc < 2) {
		printf("error: missing command line arguments\n");
	} else {
		for (i = 1; i < argc; i++) {
			j = 0;
			while ((ch = argv[i][j++]) != '\0')
				putchar(toupper(ch));
			putchar(' ');
		}
		putchar('\n');
	}
}
