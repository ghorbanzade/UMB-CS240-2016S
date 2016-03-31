/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

void reverse(int *a, int size);
void swap(int *a, int *b);

int main(void)
{
	int i;
	int size;
	int a[] = {1, 2, 3, 4, 5, 6};
	size = sizeof(a) / sizeof(a[0]);
	reverse(a, size);
	for (i = 0; i < size; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void reverse(int *a, int size)
{
	int i;
	for (i = 0; i < size / 2; i++) {
		swap(a + i, a + size - i -1);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
