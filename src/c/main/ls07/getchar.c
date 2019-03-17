/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
