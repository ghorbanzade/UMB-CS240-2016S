/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

int main(void)
{
	char *spring[] = {"March", "April", "May"};
	char summar[][15] = {"June", "July", "August"};
	printf("%s\n", spring[0]);       // March
	printf("%s\n", summar[2]);       // August
	printf("%zu\n", sizeof(spring)); // 24
	printf("%zu\n", sizeof(summar)); // 45
}
