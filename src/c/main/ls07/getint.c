/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

/**
 * convert string to integer
 */
int str2int(char str[])
{
	int i = 0;
	int res = 0;
	while (str[i] != '\0')
		res = res * 10 + str[i++] - '0';
	return res;
}

/**
 * prompt user for number n and print n^2 as ouput.
 */
int main()
{
	int i = 0;
	char ch;
	int num;
	char numstr[16];
	printf("Number: ");
	while ((ch = getchar()) != '\n')
		numstr[i++] = ch;
	numstr[i] = '\0';
	num = str2int(numstr);
	printf("%d\n", num*num);
}
