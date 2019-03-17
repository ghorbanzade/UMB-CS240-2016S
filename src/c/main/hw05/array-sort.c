/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include "array-sort.h"

/**
 *
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *
 */
void bubble_sort(int *arr, int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (arr[j + 1] < arr[j])
				swap(&arr[j], &arr[j + 1]);
}

/**
 *
 */
void insertion_sort(int *arr, int size)
{
	int i, j;
	for (i = 1 ; i <= size - 1; i++) {
		j = i;
		while (j > 0 && arr[j] < arr[j-1]) {
			swap(&arr[j], &arr[j + 1]);
			j--;
		}
	}
}

/**
 *
 */
void selection_sort(int *arr, int size)
{
	int i, j, k;
	for (i = 0; i < size - 1; i++ ) {
		k = i;
		for (j = i + 1; j < size; j++)
			if (arr[k] > arr[j])
				k = j;
		if (k != i)
			swap(&arr[i], &arr[k]);
	}
}

/**
 *
 */
void sort(int *arr, int size, void (*func)(int*, int))
{
	(*func)(arr, size);
}

/**
 *
 */
void choose_sort_algorithm(void (**func)(int *, int))
{
	int num;
	srand(time(NULL));
	num = rand() % ALGORITHM_COUNT;
	switch (num) {
	case ALGORITHM_BUBBLE:
		*func = &bubble_sort;
	case ALGORITHM_INSERTION:
		*func = &insertion_sort;
	case ALGORITHM_SELECTION:
		*func = &selection_sort;
	}
}

/**
 *
 */
int main(int argc, char *argv[])
{
	void (*func)(int*, int);
	int *arr = malloc((argc - 1) * sizeof(int));
	if (cmd2num(argc - 1, arr, argc, argv))
		return EXIT_FAILURE;
	choose_sort_algorithm(&func);
	sort(arr, argc - 1, func);
	display_array(arr, argc - 1);
	return EXIT_SUCCESS;
}
