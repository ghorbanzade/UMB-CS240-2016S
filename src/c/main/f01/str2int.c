/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <ctype.h>
#include <stdio.h>

/**
 * Updates a given pointer to an integer with a numeric value
 * that corresponds to a given string. Returns 0 if conversion
 * is successful and -1 if not.
 */
int str2int(char *str, int *num)
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
	char *str = "-s423";
	str2int(str, &num);
	printf("%d\n", num);
}
