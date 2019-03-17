/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
