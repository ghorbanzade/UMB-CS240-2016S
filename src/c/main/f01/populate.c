/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Populates a given array with random 1-digit numbers.
 */
void populate(int *arr, int size)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < size; i++)
		arr[i] = rand() % 10;
}

int main(void)
{
	int i;
	int arr[10];
	populate(&arr[0], 10);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}
