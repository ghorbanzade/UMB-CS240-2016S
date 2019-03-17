/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int str2int(char str[], int *num)
{
	char ch;
	int i = 0;
	int sign = 1;
	*num = 0;
	if (str[i] == '-') {
		sign = -1;
		i++;
	}
	while ((ch = str[i++]) != '\0') {
		if (!isdigit(ch))
			return -1;
		*num = *num * 10 + ch - '0';
	}
	*num *= sign;
	return 0;
}

int main(void)
{
	int num;
	char str[] = "-215";
	if (str2int(str, &num))
		printf("%s not a number", str);
	printf("%d\n", num);
}
