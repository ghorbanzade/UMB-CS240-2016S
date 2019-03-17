/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>
#include <string.h>

/**
 * print a message as an error
 */
void print_error(char *message)
{
	printf("error: %s\n", message);
}

/**
 * check if a given argument makes sense as a number
 */
int is_number(char *arg)
{
	int i = (arg[0] == '-') ? 1 : 0;
	while (arg[i] != '\0') {
		if (arg[i] > '9' || arg[i] < '0')
			return 0;
		i++;
	}
	return 1;
}

/**
 * print reverse of a given argument
 */
void print_reverse(char *arg)
{
	int i, j = 0;
	int len = strlen(arg);
	char rev[len];

	if (arg[0] == '-') {
		rev[0] = '-';
		j = 1;
	}
	for (i = 0; i < len - j; i++) {
		rev[i + j] = arg[len - 1 - i];
	}
	printf("Reverse: %s\n", rev);
}

/**
 * this program takes a command line argument
 * checks whether it is a valid integer number
 * and prints its reverse
 */
int main(int argc, char *argv[])
{
	if (argc >= 2) {
		char *arg = argv[1];
		if (is_number(arg)) {
			print_reverse(arg);
		} else {
			print_error("not a number");
		}
	} else {
		print_error("missing command line argument");
	}
}
