/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

/**
 * gets a number, increments its value and returns it
 */
int increment(int num)
{
	return num + 1;
}


/**
 * checks whether a given number num is a prime.
 */
int is_prime(int num)
{
	int i;
	int ret = 0;
	if (num < 2)
		goto ERROR;
	i = 2;
	while (i <= num/2)
		if (num % i++ == 0)
			goto ERROR;
	ret = 1;
ERROR:
	return ret;
}

/*
 * the main function calls the previously declared
 * is_prime function to check whether 101 is a prime.
 */
int main(void)
{
	int number = increment(100);
	if (is_prime(number))
		printf("%d is a prime\n", number);
	else
		printf("%d is not a prime\n", number);
}