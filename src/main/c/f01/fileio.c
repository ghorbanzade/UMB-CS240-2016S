/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 16
#define FILE1 "file1.txt"
#define FILE2 "file2.txt"

int main(void)
{
	FILE *ptr1, *ptr2;
	char line[MAX_LENGTH];
	ptr1 = fopen(FILE1, "r+");
	if (ptr1 == NULL) {
		printf("unable to open file1.txt\n");
		return EXIT_FAILURE;
	}
	ptr2 = fopen(FILE2, "w");
	if (ptr2 == NULL) {
		printf("unable to open file1.txt\n");
		goto ERR;
	}
	while (fgets(line, MAX_LENGTH, ptr1))
		fputs(line, ptr2);
	fclose(ptr2);
 ERR:
	fclose(ptr1);
	return EXIT_SUCCESS;
}
