/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "slow-prime.h"

/**
 * get a number as command line argument and
 * print the first prime number bigger than the given number
 */
int main(int argc, char *argv[])
{
	int num;
	int nxt;
	int ret = EXIT_FAILURE;
	if (argc < 2) {
		printf("error: missing command line argument\n");
		goto ERROR;
	}
	if (get_number(argv[1], &num)) {
		printf("error: %s not a number\n", argv[1]);
		goto ERROR;
	}
	next_prime(num, &nxt);
	printf("%d\n", nxt);
	ret = EXIT_SUCCESS;
ERROR:
	return ret;
}

/**
 * convert string to number, assuming number is positive
 */
int get_number(char *str, int *num)
{
	char ch;
	int i = 0;
	int ret = -1;
	int res = 0;
	*num = 0;
	while ((ch = str[i]) != '\0') {
		if (!isdigit(ch))
			goto ERROR;
		res = res * 10 + str[i++] - '0';
	}
	*num = res;
	ret = 0;
ERROR:
	return ret;
}

/**
 * update nxt with first prime bigger than number num
 */
void next_prime(int num, int *nxt)
{
	while (!is_prime(++num));
	*nxt = num;
}

/**
 * check if a given number is prime
 */
int is_prime(int num)
{
	int ret = 0;
	int i;
	for (i = 2; i < num / 2; i++) {
		if (num % i == 0)
			goto ERROR;
	}
	ret = 1;
ERROR:
	return ret;
}
