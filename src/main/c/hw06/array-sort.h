/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#ifndef ARRAY_SORT_H
#define ARRAY_SORT_H

#include "array-utils.h"

typedef enum {
	ALGORITHM_BUBBLE,
	ALGORITHM_INSERTION,
	ALGORITHM_SELECTION,
	ALGORITHM_COUNT
} algorithm_spec;

void swap(int *a, int *b);
void bubble_sort(int *arr, int size);
void insertion_sort(int *arr, int size);
void selection_sort(int *arr, int size);
void sort(int *arr, int size, void (*func)(int*, int));
void choose_sort_algorithm(void (**func)(int *, int));

#endif // ARRAY_SORT_H
