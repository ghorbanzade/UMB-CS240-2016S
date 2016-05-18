/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "array-list.h"

/**
 * Allocates memory for an arraylist with an initial size.
 */
void arraylist_init(ArrayList *list)
{
	list->nmemb = 0;
	list->size = INITIAL_SIZE;
	list->elements = malloc(INITIAL_SIZE * sizeof(int));
	assert(list->elements);
}

/**
 * Adds a new integer to the end of an arraylist.
 */
void arraylist_add(ArrayList *list, int value)
{

	if (list->size <= list->nmemb * sizeof(int)) {
		list->size *= 2;
		list->elements = realloc(list->elements, list->size);
		assert(list->elements);
	}
	list->elements[list->nmemb++] = value;
}

/**
 * Prints elements of the arraylist and its metadata on standard output.
 */
void arraylist_print(ArrayList *list)
{
	int i;
	printf(
		"size: %2d, capacity: %2zu B, elements: ",
		list->nmemb,
		list->size
	);
	for (i = 0; i < list->nmemb; i++)
		printf("%d ", list->elements[i]);
	putchar('\n');
}

/**
 * Returns the element in index i of a given arraylist.
 */
int arraylist_get(ArrayList *list, unsigned int index)
{
	assert(index < list->nmemb);
	return list->elements[index];
}

/**
 * Replaces the element in index i of an arraylist with a new element.
 * Returns previous element in the given index.
 */
int arraylist_set(ArrayList *list, unsigned int index, int value)
{
	int out = 0;
	assert(index < list->nmemb);
	out = arraylist_get(list, index);
	list->elements[index] = value;
	return out;
}

/**
 * Demonstrates how arraylist is resized as elements are being added.
 */
int main(void)
{
	int i;
	ArrayList list;
	arraylist_init(&list);
	for (i = 0; i < 10; i++) {
		arraylist_add(&list, 10 - i);
		arraylist_print(&list);
	}
	arraylist_set(&list, 4, 0);
	arraylist_print(&list);
	free(list.elements);
}
