/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "daltons.h"

/**
 * take height of brothers as command line arguments and print their names
 * in ascending order of their heights
 */
int main(int argc, char *argv[])
{
	int ret = EXIT_FAILURE;
	struct brother brothers[BROTHER_NUM];
	char *names[] = {"Joe", "Jack", "William", "Averell"};

	if (argc <= BROTHER_NUM) {
		printf("error: missing command line arguments\n");
		goto ERROR;
	}
	if (init(brothers, BROTHER_NUM, names, argv))
		goto ERROR;
	sort(brothers, BROTHER_NUM);
	show(brothers, BROTHER_NUM);
	ret = EXIT_SUCCESS;
 ERROR:
	return ret;
}

/**
 * convert a string to integer
 */
int str2num(char *str, int *num)
{
	char ch;
	int i = 0;
	int sign = 1;
	*num = 0;
	if (str[i] == '-') {
		sign = -1;
		i++;
	}
	while ((ch = str[i++]) != '\0') {
		if (!isdigit(ch))
			return -1;
		*num = *num * 10 + ch - '0';
	}
	*num *= sign;
	return 0;
}

/**
 * load names and heights of brothers
 */
int init(struct brother *brothers, int count, char *names[], char *argv[])
{
	int i;
	for (i = 0; i < count; i++) {
		brothers[i].name = names[i];
		if (str2num(argv[i + 1], &brothers[i].height)) {
			printf("error: %s not a number", argv[i + 1]);
			return -1;
		}
	}
	return 0;
}

/**
 * swap one brother with another
 */
void swap(struct brother *a, struct brother *b)
{
	struct brother tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sort an array of brothers
 */
void sort(struct brother *brothers, int const count)
{
	int i, j;
	for (i = 0; i < count - 1; i++)
		for (j = 0; j < count - i - 1; j++)
			if (brothers[j + 1].height < brothers[j].height)
				swap(&brothers[j], &brothers[j + 1]);
}

/**
 * print names of brothers
 */
void show(struct brother *brothers, int const count)
{
	int i;
	for (i = 0; i < count; i++) {
		printf("%s %d\n", brothers[i].name, brothers[i].height);
	}
}
