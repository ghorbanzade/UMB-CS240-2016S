/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

int main(void)
{
	char *a[2];
	a[0] = "Hello";
	a[1] = "world!";
	printf("%s\n", a[0]);       // Hello
	printf("%s\n", a[1]);       // world!
	printf("%c\n", a[0][1]);    // e
	printf("%c\n", a[0][6]);    // w
	printf("%zu\n", sizeof(a)); // 16
}
