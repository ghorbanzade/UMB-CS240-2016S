/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#ifndef ARRAY_GENERATE_H
#define ARRAY_GENERATE_H

#include "array-utils.h"

typedef enum {
	ARRAY_COUNT,
	ARRAY_MIN_VALUE,
	ARRAY_MAX_VALUE,
	ARRAY_ENUM_COUNT
} array_spec;

int rand_num(int *num, int min, int max);
int generate_array(int *arr, int cnt, int min, int max);

#endif // ARRAY_GENERATE_H
