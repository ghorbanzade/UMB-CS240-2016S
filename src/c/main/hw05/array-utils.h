/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_error(char *msg);
void display_array(int *arr, int size);
int str2num(char *str, int *num);
int cmd2num(int count, int *cfg, int argc, char *argv[]);

#endif // ARRAY_UTILS_H
