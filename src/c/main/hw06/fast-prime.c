/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "fast-prime.h"

/**
 * this program takes a number of integers as command-line arguments
 * and uses an efficient variant of trial-division algorithm to check
 * whether they are prime or not.
 * prime numbers found during program execution are stored and reused
 * to expedite run-time of succeeding program calls.
 */
int main(int argc, char *argv[])
{
	int i;
	int num;
	int ret = EXIT_FAILURE;
	if (argc < 2) {
		printf("error: missing command line argument\n");
		goto ERROR;
	}
	for (i = 1; i < argc; i++) {
		if (str2int(argv[i], &num)) {
			printf("%s: not a number\n", argv[i]);
			continue;
		}
		if (prime_check(num))
			printf("%d: not prime\n", num);
		else
			printf("%d: prime\n", num);
	}
	ret = EXIT_SUCCESS;
 ERROR:
	return ret;
}

/**
 * this helper function converts a numeric string to an integer.
 */
int str2int(char *str, int *num)
{
	*num = 0;
	char ch;
	int i = 0;
	int ret = -1;
	int sign = 1;
	if (str[i] == '-') {
		sign = -1;
		i++;
	}
	while ((ch = str[i++]) != '\0') {
		if (!isdigit(ch))
			goto ERROR;
		*num = *num * 10 + ch - '0';
	}
	*num *= sign;
	ret = 0;
 ERROR:
	return ret;
}

/**
 * this function checks whether a given integer is prime or not
 */
int prime_check(int num)
{
	int *primes = NULL;
	int primes_size;
	int ret = -1;
	if (num < 2)
		goto ERROR;
	if (read_primes(&primes, &primes_size)) {
		printf("error: unable to read list of prime numbers\n");
		goto ERROR;
	}
	if (check_on_set(num, primes, primes_size))
		goto ERROR;
	if (check_beyond(num, &primes, &primes_size))
		goto ERROR;
	ret = 0;
 ERROR:
	free(primes);
	return ret;
}

/**
 * read list of prime numbers from file.
 */
int read_primes(int **primes, int *size)
{
	FILE *fp;
	int prime;
	int ret = -1;
	int asize = 1;
	char line[LINE_WIDTH];
	*size = 0;
	*primes = malloc(asize * sizeof(int));
	fp = fopen(PRIME_LIST, "a+");
	if (fp == NULL)
		goto ERROR;
	while (fgets(line, LINE_WIDTH, fp) != NULL) {
		line[strlen(line) - 1] = '\0';
		if (str2int(line, &prime))
			goto ERROR;
		(*primes)[(*size)++] = prime;
		if (*size >= asize) {
			asize *= 2;
			*primes = realloc(*primes, asize * sizeof(int));
		}
	}
	if (*size == 0)
		(*primes)[(*size)++] = 2;
	ret = 0;

 ERROR:
	if (fp != NULL)
		fclose(fp);
	return ret;
}

/**
 * check if any element of the list of known primes is a factor
 * of a given number.
 */
int check_on_set(int num, int *primes, int size)
{
	int i;
	int ret = -1;
	for (i = 0; i < size; i++) {
		if (num / 2 < primes[i])
			break;
		if (num % primes[i] == 0)
			goto ERROR;
	}
	ret = 0;
 ERROR:
	return ret;
}

/**
 * check if a given number which is bigger than the largest known prime
 * number is prime or not.
 * this function updates the list of known prime numbers to include
 * all prime numbers less than given number.
 */
int check_beyond(int num, int **primes, int *size)
{
	int ret = -1;
	int cur = (*primes)[*size - 1];
	int asize = get_alloc_size(*size);
	while (++cur <= num) {
		if (check_on_set(cur, *primes, *size))
			continue;
		if (asize < *size) {
			asize *= 2;
			*primes = realloc(*primes, asize * sizeof(int));
		}
		(*primes)[(*size)++] = cur;
	}
	if (check_on_set(num, *primes, *size))
		goto ERROR;
	ret = 0;
 ERROR:
	if (write_primes(*primes, *size))
		printf("error: unable to save new primes\n");
	return ret;
}

/**
 * check number of integers possible to store in the current list
 * of prime numbers.
 */
int get_alloc_size(int size)
{
	int i = 0;
	int ret = 2;
	while ((size /= 2) > 0)
		i++;
	while (i-- > 0)
		ret *= 2;
	return ret;
}

/**
 * store the list of known prime numbers in a file.
 */
int write_primes(int *primes, int primes_size)
{
	int i;
	FILE *fp;
	int ret = -1;

	fp = fopen(PRIME_LIST, "w");
	if (fp == NULL)
		goto ERROR;
	for (i = 0; i < primes_size; i++)
		fprintf(fp, "%d\n", primes[i]);
	ret = 0;

 ERROR:
	if (fp != NULL)
		fclose(fp);
	return ret;
}
