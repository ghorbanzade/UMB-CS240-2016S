/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 */
int **func(int size)
{
	int i;
	int j;
	int **matrix = malloc(size * sizeof(int *));
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		matrix[i] = malloc(size * sizeof(int));
		for (j = 0; j < size; j++)
			matrix[i][j] = rand() % 10;
	}
	return matrix;
}

/**
 *
 */
void print(int **matrix, int size)
{
	int i;
	int j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%d ", matrix[i][j]);
		putchar('\n');
	}
}

/**
 *
 */
int main(int argc, char *argv[])
{


	int size;
	int **matrix;
	if (argc < 2) {
		printf("error: missing command line arguments\n");
		printf("usage: %s [size]\n", argv[0]);
		return 1;
	}
	size = atoi(argv[1]);
	matrix = func(size);
	print(matrix, size);
}
