/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
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