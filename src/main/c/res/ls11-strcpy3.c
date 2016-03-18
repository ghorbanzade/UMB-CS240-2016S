/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

void our_strcpy(char *s, char *t)
{
	while (*s++ = *t++);
}

int main(void)
{
	char a[20] = "Hello";
	char b[20];
	our_strcpy(b, a);
	printf("b: %s\n", b);
}
