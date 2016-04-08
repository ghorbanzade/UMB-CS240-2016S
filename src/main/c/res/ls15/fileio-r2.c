/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#define MAXLEN 16

int main(void)
{
	FILE *fp;
	char buff[MAXLEN];
	fp = fopen("sample.txt", "r");
	while (fgets(buff, MAXLEN, fp) != NULL)
		printf("%s", buff);
	fclose(fp);
}
