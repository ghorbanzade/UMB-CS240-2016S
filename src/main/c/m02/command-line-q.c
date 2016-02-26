/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

// Bellatrix Lestrange
// <bellatrix.lestran001@umb.edu>

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i;
	int sum = 0;
	float avg;
	for (i = 0; i < argc; i++)
		sum += str2num(argv[i]);
	avg = sum / argc;
	printf("%.2f\n", avg);
}

int str2num(char str[])
{
	int i;
	int res = 0;
	for (i = 0; i < sizeof(str); i++)
		res = res * 10 + str[i] - '0';
	return res;
}
