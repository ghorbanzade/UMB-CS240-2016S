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

int main(void)
{
	char a[20] = "Hello";
	char b[] = "Hello";
	char *c = "Hello";
	printf("sizeof a: %zu\n", sizeof(a)); // 20
	printf("sizeof b: %zu\n", sizeof(b)); // 6
	printf("sizeof c: %zu\n", sizeof(c)); // 8
	printf("strlen a: %zu\n", strlen(a)); // 5
	printf("strlen b: %zu\n", strlen(b)); // 5
	printf("strlen c: %zu\n", strlen(c)); // 5
}
