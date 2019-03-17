/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
