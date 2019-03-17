/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include "array-list.h"

/**
 * allocates memory for an arraylist with an initial size.
 */
void arraylist_init(struct arraylist *list)
{
	list->nmemb = 0;
	list->size = INITIAL_SIZE;
	list->elements = malloc(INITIAL_SIZE * sizeof(int));
	assert(list->elements);
}

/**
 * deallocates memory assigned to an arraylist.
 */
void arraylist_free(struct arraylist *list)
{
	free(list->elements);
	free(list);
}

/**
 * reallocates an arraylist to fit elements of given size.
 */
void arraylist_allocate(struct arraylist *list, size_t size)
{
	if (size < list->size)
		return;
	size_t new_size = list->size;
	while (new_size < size)
		new_size *= 2;
	list->elements = realloc(list->elements, new_size);
	assert(list->elements);
	list->size = new_size;
}

/**
 * adds a new integer to the end of an arraylist.
 */
void arraylist_add(struct arraylist *list, int value)
{
	arraylist_allocate(list, (list->nmemb + 1) * sizeof(int));
	list->elements[list->nmemb++] = value;
}

/**
 * removes the element with given index from the arraylist.
 */
int arraylist_remove_by_index(struct arraylist *list, const unsigned int index)
{
	int ret;
	assert(index < list->nmemb);
	ret = list->elements[index];
	memmove(
		list->elements + index,
		list->elements + index + 1,
		(list->nmemb - index) * sizeof(int)
	);
	list->nmemb--;
	return ret;
}

/**
 * removes an element with a given numeric value from the arraylist.
 * returns the index of the removed element.
 */
int arraylist_remove_by_value(struct arraylist *list, int value)
{
	int i;
	int ret = -1;
	for (i = 0; i < list->nmemb; i++)
		if (list->elements[i] == value) {
			ret = i;
			memmove(
				list->elements + i,
				list->elements + i + 1,
				(list->nmemb - i) * sizeof(int)
			);
			list->nmemb--;
			break;
		}
	return ret;
}

/**
 * returns number of elements inside the arraylist.
 */
int arraylist_size(struct arraylist *list)
{
	return list->nmemb;
}

/**
 * inserts a new element to a given index of the arraylist.
 */
void arraylist_insert(struct arraylist *list, unsigned int index, int value)
{
	arraylist_allocate(list, (list->nmemb + 1) * sizeof(int));
	memmove(
		list->elements + index,
		list->elements + index + 1,
		(list->nmemb - index) * sizeof(int)
	);
	list->elements[index] = value;
}

/**
 * replaces element of the arraylist in a given index with a new given element.
 */
void arraylist_set(struct arraylist *list, unsigned int index, int value)
{
	assert(index < list->nmemb);
	list->elements[index] = value;
}

/**
 * returns value of an element in a given index in the arraylist.
 */
int arraylist_get(struct arraylist *list, unsigned int index)
{
	assert(index < list->nmemb);
	return list->elements[index];
}

/**
 * returns index of an element with a given value in the arraylist.
 * returns -1 if no element with the given value exists.
 */
int arraylist_indexof(struct arraylist *list, int value)
{
	int i;
	for (i = 0; i < list->nmemb; i++)
		if (list->elements[i] == value)
			return i;
	return -1;
}

/**
 * returns whether the arraylist has any elements or not
 */
int arraylist_isempty(struct arraylist *list)
{
	return list->nmemb;
}

/**
 * prints elements of the arraylist and its metadata on standard output.
 */
void arraylist_print(struct arraylist *list)
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
 * demonstrates how an arraylist can be used.
 */
int main(void)
{
	int i;
	struct arraylist list;
	arraylist_init(&list);
	for (i = 0; i < 10; i++) {
		arraylist_add(&list, 10 - i);
		arraylist_print(&list);
	}
	arraylist_remove_by_index(&list, 1);
	arraylist_print(&list);
	arraylist_remove_by_value(&list, 6);
	arraylist_print(&list);
	arraylist_set(&list, 2, 0);
	arraylist_print(&list);
}
