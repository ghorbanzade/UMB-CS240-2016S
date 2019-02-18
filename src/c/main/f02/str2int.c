/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <ctype.h>
#include <stdio.h>

/**
 *
 */
int func(char *str, int *num)
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

/**
 *
 */
int main(int argc, char *argv[])
{
	int num;
	if (argc < 2) {
		printf("error: missing command line arguments\n");
		printf("usage: %s [number]\n", argv[0]);
		return 1;
	}
	if (func(argv[1], &num))
		printf("conversion not possible\n");
	else
		printf("%d\n", num);
}
