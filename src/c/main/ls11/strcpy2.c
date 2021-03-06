/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

void our_strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

int main(void)
{
	char a[20] = "Hello";
	char b[20];
	our_strcpy(b, a);
	printf("b: %s\n", b);
}
