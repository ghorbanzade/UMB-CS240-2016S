/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

/**
 * Checks whether a given string is palindrome or not.
 * Returns 1 if palindrome is detected and 0 if not.
 */
int is_palindrome(char *str)
{
	int i;
	int len = 0;
	while (str[len++] != '\0');
	for (i = 0; i < len / 2; i++)
		if (str[i] != str[len - i - 2])
			return 0;
	return 1;
}

int main(void)
{
	char *str = "fbttbf";
	if (is_palindrome(str))
		printf("palindrome\n");
	else
		printf("not palindrome\n");
}
