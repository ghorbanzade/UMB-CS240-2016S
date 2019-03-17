/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 2 * sizeof(int)

typedef struct arraylist {
	int *elements;
	int nmemb;
	size_t size;
} ArrayList;

void arraylist_init(ArrayList *list);
void arraylist_add(ArrayList *list, int value);
int arraylist_get(ArrayList *list, unsigned int index);
int arraylist_set(ArrayList *list, unsigned int index, int value);
void arraylist_print(ArrayList *list);

#endif // ARRAY_LIST_H
