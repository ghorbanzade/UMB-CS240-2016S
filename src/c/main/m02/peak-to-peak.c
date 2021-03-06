/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>
#include <string.h>

int peak_to_peak(int array[], int size);

int main(int argc, char *argv[])
{
	int diff;
	int array[] = {-1, 2, 3, 0, 2, 6};
	int size = sizeof(array)/sizeof(array[0]);
	diff = peak_to_peak(array, size);
	printf("%d\n", diff);
}

int peak_to_peak(int array[], int size)
{
	int i;
	int min = array[0];
	int max = array[0];
	for (i = 0; i < size; i++) {
		min = (array[i] < min) ? array[i] : min;
		max = (array[i] > max) ? array[i] : max;
	}
	return max - min;
}
