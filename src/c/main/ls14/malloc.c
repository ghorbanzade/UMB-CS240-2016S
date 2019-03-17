/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int size = 10;
	int *array = calloc(size, sizeof(int));
	if (array == NULL) {
		printf("failed to allocate memory\n");
	} else {
		printf("allocated %zu bytes\n", size * sizeof(int));
		free(array);
	}
	return 0;
}
