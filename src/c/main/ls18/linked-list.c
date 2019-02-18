/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "linked-list.h"

/**
 * creates a linked list with a given element.
 */
struct node *init(int value)
{
	struct node *list;
	list = malloc(sizeof(struct node));
	list->next = NULL;
	list->value = value;
	return list;
}

/**
 * deallocated memory assigned to a linked list.
 */
void list_free(struct node *list)
{
	struct node *curr;
	while ((curr = list) != NULL) {
		list = list->next;
		free(curr);
	}
}

/**
 * adds an element to a given index of a linked list.
 */
void insert(struct node *list, unsigned int index, int value)
{
	struct node *new;
	int count = 0;
	while (list) {
		if (count == index) {
			new = malloc(sizeof(struct node));
			new->value = list->value;
			new->next = list->next;
			list->value = value;
			list->next = new;
			return;
		}
		list = list->next;
		count++;
	}
}

/**
 * adds an element to the end of a linked list.
 */
void append(struct node *list, int value)
{
	struct node *new = malloc(sizeof(struct node));
	new->next = NULL;
	new->value = value;
	while (list->next) {
		list = list->next;
	}
	list->next = new;
}

/**
 * adds an element to the head of a linked list.
 */
void prepend(struct node *list, int value)
{
	insert(list, 0, value);
}

/**
 * removes an element in a given index from a linked list.
 */
int remove_by_index(struct node *list, unsigned int index)
{
	int ret;
	int count = 0;
	struct node *tmp;
	while (list != NULL) {
		if (count == index) {
			ret = list->next->value;
			tmp = list->next;
			list->next = list->next->next;
			free(tmp);
			return ret;
		}
		list = list->next;
		count++;
	}
	return -1;
}

/**
 * returns the number of elements of a linked list.
 */
int size(struct node *list)
{
	int i = 0;
	while (list) {
		list = list->next;
		i++;
	}
	return i;
}

/**
 * returns value of an element in a given index in the array.
 */
int get(struct node *list, unsigned int index)
{
	int count = 0;
	while (list) {
		if (count == index)
			return list->value;
		list = list->next;
		count++;
	}
	return -1;
}

/**
 * replaces element of a linked list in a given index with a new given element.
 */
void set(struct node *list, unsigned int index, int value)
{
	int count = 0;
	while (list) {
		if (count == index) {
			list->value = value;
			return;
		}
		list = list->next;
		count++;
	}
}

/**
 * returns index of an element in a linked list with a given value.
 * returns -1 if no element in linked list has the specified value.
 */
int indexof(struct node *list, int value)
{
	int count = 0;
	while (list) {
		if (list->value == value)
			return count;
		list = list->next;
		count++;
	}
	return -1;
}

/**
 * returns whether linked list has any element or not.
 */
int is_empty(struct node *list)
{
	return (list) ? 0 : 1;
}

/**
 * prints all the elements of a linked list.
 */
void print(struct node *list)
{
	do {
		printf("%d ", list->value);
	} while ((list = list->next) != NULL);
	putchar('\n');
}

/**
 *
 */
int main(void)
{
	struct node *list = init(12);
	append(list, 13);
	append(list, 14);
	prepend(list, 11);
	append(list, 15);
	append(list, 16);
	print(list);
	printf("size: %d\n", size(list));
	printf("index for 14: %d\n", indexof(list, 14));
	set(list, 2, 20);
	print(list);
	printf("index for 14: %d\n", indexof(list, 14));
	insert(list, 1, 300);
	print(list);
	remove_by_index(list, 1);
	print(list);
	free(list);
}
