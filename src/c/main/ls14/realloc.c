/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr1, *ptr2;
	ptr1 = malloc(10 * sizeof(int));
	if (ptr1 == NULL)
		goto ERROR;
	ptr2 = realloc(ptr1, 20 * sizeof(int));
	if (ptr2 == NULL) {
		free(ptr1);
		goto ERROR;
	}
	free(ptr2);
 ERROR:
	return 0;
}
