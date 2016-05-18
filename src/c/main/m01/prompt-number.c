/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#define MAX_LENGTH 32

int getNum(void)
{
	int res = 0;
	char ch;
	int i = 0;
	char array[MAX_LENGTH];
	while ((ch = getchar()) != '\n')
		array[i++] = ch;
	array[i] = '\0';
	i = 0;
	while (array[i] != '\0')
		res = res * 10 + array[i++] - '0';
	return res;
}

int main(void)
{
	int num = getNum();
	printf("%d\n", num);
}
