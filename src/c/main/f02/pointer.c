/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
