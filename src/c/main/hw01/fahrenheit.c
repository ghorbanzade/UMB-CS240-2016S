/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

#define MIN 60
#define MAX 100
#define STEP 10

int main(void)
{
	int tempC, tempF;
	printf(" %-4s %-4s \n", "C", "F");
	printf("-----------\n");
	for (tempC = MIN; tempC <= MAX; tempC += STEP) {
		tempF = tempC * 9 / 5 + 32;
		printf(" %-4d %-4d\n", tempC, tempF);
	}
}
