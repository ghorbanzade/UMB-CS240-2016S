/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "reverse.h"

int main(void)
{
	char *str = NULL;
	char *rev;
	printf("string: ");
	scanf("%s", str);
	rev = reverse(str);
	printf("reversed string: %s\n", rev);
	free(rev);
}

char *reverse(char *str)
{
	int j;
	int i = 0;
	char *ret;
	while (str[i++] != '\0');
	ret = malloc(i);
	assert(ret); // abort the program if ret is null
	for (j = 0; j < i; j++)
		ret[j] = str[i - j - 2];
	ret[j] = '\0';
	return ret;
}
