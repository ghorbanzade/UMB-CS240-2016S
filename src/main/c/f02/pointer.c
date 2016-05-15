/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

void func1(char *str)
{
	str = "Fall";
}

void func2(int num)
{
	num++;
}

int main(void)
{
	int num = 2016;
	char *str = "Spring";
	func1(str);
	func2(num);
	printf("%s %d!\n", str, num);
}
