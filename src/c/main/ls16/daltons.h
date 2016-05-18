/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#ifndef DALTONS_H
#define DALTONS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define BROTHER_NUM 4

struct brother {
	char *name;
	int height;
};
int str2num(char *str, int *num);
int init(struct brother *brothers, int count, char *names[], char *argv[]);
void swap(struct brother *a, struct brother *b);
void sort(struct brother * brothers, int const count);
void show(struct brother *brothers, int const count);

#endif // DALTONS_H
