/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

/**
 * checks whether a given number is not prime
 */
int not_prime(int num)
{
	int i = 2;
	for (i = 2; i < num / 2; i++)
		if (num % i == 0)
			return 1;
	return 0;
}

/**
 * returns the smallest prime number bigger than a given number
 */
int prime(int num)
{
	int tmp = num + 1;
	while (not_prime(tmp))
		tmp++;
	return tmp;
}

/**
 * asks user for a character of the set
 */
int prompt(void)
{
	char c;
	while (1) {
		printf("another number [y/n]? ");
		c = getchar();
		while (getchar() != '\n');
		if (c == 'y' || c == 'Y')
			return 1;
		else if (c == 'n' || c == 'N')
			return 0;
		else
			printf("invalid input\n");
	}
}

/**
 * this program prints a prime number and continues to do so
 * as long as the user enters y or Y. Program terminates when
 * user enters n or N.
 */
int main(void)
{
	int i = 1;
	do {
		int p = prime(i);
		printf("%d\n", p);
		i = p;
	} while (prompt());
}
