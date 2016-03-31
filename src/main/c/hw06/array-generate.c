/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "array-generate.h"

/**
 *
 */
int main(int argc, char *argv[])
{
	int *arr;
	int *cfg = malloc(ARRAY_ENUM_COUNT * sizeof(int));
	if (cmd2num(ARRAY_ENUM_COUNT, cfg, argc, argv))
		return EXIT_FAILURE;
	arr = malloc(cfg[ARRAY_COUNT]);
	if (generate_array(arr, cfg[ARRAY_COUNT], cfg[ARRAY_MIN_VALUE], cfg[ARRAY_MAX_VALUE]))
		return EXIT_FAILURE;
	display_array(arr, cfg[ARRAY_COUNT]);
	return EXIT_SUCCESS;
}

/**
 *
 */
int rand_num(int *num, int min, int max) {
	*num = 0;
	if (max < min) {
		print_error("min is bigger than max");
		return -1;
	}
	*num = min + rand() % (max - min);
	return 0;
}

/**
 *
 */
int generate_array(int *arr, int cnt, int min, int max) {
	if (cnt <= 0) {
		print_error("array size must be positive");
		return -1;
	} 
	srand(time(NULL));
	int i;
	for (i = 0; i < cnt; i++)
		if (rand_num((arr+i), min, max))
			return -1;
	return 0;
}
