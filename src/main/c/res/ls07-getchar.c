/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

/**
 * ask user name and print it.
 */
int main()
{
	int i = 0;
	char ch;
	char name[32];
	printf("Your name: ");
	while ((ch = getchar()) != '\n')
		name[i++] = ch;
	name[i] = '\0';
	printf("Hello %s!\n", name);
}
