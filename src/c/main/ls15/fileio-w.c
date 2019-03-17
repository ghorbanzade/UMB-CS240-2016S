/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int main(void)
{
	FILE *fp;
	fp = fopen("sample.txt", "w");
	fprintf(fp, "content of the file\n");
	fclose(fp);
}
