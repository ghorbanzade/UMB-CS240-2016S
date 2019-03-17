/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>
#include <string.h>

int str2num(char str[]);

int main(int argc, char *argv[])
{
	int i;
	float sum = 0;
	float avg;
	if (argc < 2) {
		printf("error: missing command line arguments\n");
	} else {
		for (i = 1; i < argc; i++)
			sum += str2num(argv[i]);
		avg = sum / (argc - 1);
		printf("%.2f\n", avg);
	}
}

int str2num(char str[])
{
	int i;
	int res = 0;
	for (i = 0; i < strlen(str); i++)
		res = res * 10 + str[i] - '0';
	return res;
}
