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

#define INITIAL_SIZE 2

struct arraylist {
	int *elements;
	int nmemb;
	size_t size;
};

void arraylist_init(struct arraylist *list);
void arraylist_free(struct arraylist *list);
void arraylist_allocate(struct arraylist *list, size_t size);
void arraylist_add(struct arraylist *list, int value);
int arraylist_remove_by_index(struct arraylist *list, const unsigned int index);
int arraylist_remove_by_value(struct arraylist *list, int value);
int arraylist_size(struct arraylist *list);
void arraylist_insert(struct arraylist *list, unsigned int index, int value);
void arraylist_set(struct arraylist *list, unsigned int index, int value);
int arraylist_get(struct arraylist *list, unsigned int index);
int arraylist_indexof(struct arraylist *list, int value);
int arraylist_isempty(struct arraylist *list);
void arraylist_print(struct arraylist *list);

#endif // ARRAY_LIST_H
