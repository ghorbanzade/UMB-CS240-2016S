/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_error(char *msg);
void display_array(int *arr, int size);
int str2num(char *str, int *num);
int cmd2num(int count, int *cfg, int argc, char *argv[]);

#endif // ARRAY_UTILS_H
