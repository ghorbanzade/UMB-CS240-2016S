/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
