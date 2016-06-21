/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
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