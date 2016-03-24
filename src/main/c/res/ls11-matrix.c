/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

void show(int *m, int size);
void multiply(int *m, int size);
int calc(int *m, int row, int col, int size);
void copy(int *m, int *n, int size);

int main(void)
{
	int a[3][3] = {
		{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
	};
	int size = sizeof(a)/sizeof(a[0]);
	show(&a[0][0], size);
	multiply(&a[0][0], size);
	show(&a[0][0], size);
}

void show(int *m, int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%3d ", *(m + size * i + j));
		printf("\n");
	}
}

void multiply(int *m, int size)
{
	int i, j;
	int n[size][size];
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			n[i][j] = calc(m, i, j, size);
	copy(m, &n[0][0], size);
}

int calc(int *m, int row, int col, int size)
{
	int i;
	int *p, *q;
	int sum = 0;
	for (i = 0; i < size; i++) {
		p = m + size * row + i;
		q = m + size * i + col;
		sum += (*p) * (*q);
	}
	return sum;
}

void copy(int *m, int *n, int size)
{
	int i;
	for (i = 0; i < size * size; i++)
		*m++ = *n++;
}
