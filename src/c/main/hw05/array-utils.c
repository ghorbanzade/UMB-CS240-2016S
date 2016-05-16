/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "array-utils.h"

/**
 *
 */
void print_error(char *msg)
{
	fprintf(stderr, "error: %s\n", msg);
}

/**
 *
 */
void display_array(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	putchar('\n');
}

/**
 *
 */
int str2num(char *str, int *num)
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
		*num = (*num) * 10 + ch - '0';
	}
	*num *= sign;
	return 0;
}

 /**
  *
  */
int cmd2num(int count, int *arr, int argc, char *argv[])
{
	int i;
	if (argc < count + 1) {
		print_error("missing command line arguments");
		return -1;
	}
	for (i = 0; i < count; i++) {
		if (str2num(argv[i + 1], arr + i)) {
			print_error("argument not a number");
			return -1;
		}
	}
	return 0;
}
