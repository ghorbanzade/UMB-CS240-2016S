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

struct arraylist {
	int *elements;
	int nmemb;
	size_t size;
};

void arraylist_init(struct arraylist *list);
void arraylist_add(struct arraylist *list, int value);
void arraylist_print(struct arraylist *list);

#endif // ARRAY_LIST_H
