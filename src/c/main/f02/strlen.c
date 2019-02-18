/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#include <string.h>

/**
 * Implementation of strlen function that returns length of string as integer.
 */
int my_strlen(char *str)
{
	int i = 0;
	while (*(str++) != '\0')
		i++;
	return i;
}

/**
 * Program to compare functionality of my_strlen() agains strlen().
 */
int main(void)
{
	char *name = "Goodbye CS240!";
	printf("length: %d\n", my_strlen(name));
	printf("length: %d\n", (int) strlen(name));
}
