/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int single_number(int array[], int size);

int main(void)
{
	int out;
	int array[] = {1, -1, 4, 5, 4, 1, -1};
	int size = sizeof(array) / sizeof(array[0]);
	out = single_number(array, size);
	printf("%d\n", out);
}

int single_number(int array[], int size)
{
	int i;
	int res = 0;
	for (i = 0; i < size; i++)
		res = res ^ array[i];
	return res;
}
