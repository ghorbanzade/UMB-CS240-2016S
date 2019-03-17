/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
