/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[10] = "hello";
	printf("%d ", (int) strlen(string));
	printf("%d\n", (int) sizeof(string));
}
