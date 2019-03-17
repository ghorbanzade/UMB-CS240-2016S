/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int main(void)
{
	char ch;
	FILE *fp;
	fp = fopen("sample.txt", "r");
	while ((ch = fgetc(fp)) != EOF)
		putchar(ch);
	fclose(fp);
}
