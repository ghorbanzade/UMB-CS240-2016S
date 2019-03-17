/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 16

union data {
	int member1;
	float member2;
	char member3[MAX_LENGTH];
};

int main(void)
{
	union data mydata;
	mydata.member1 = 10;
	printf("value of union: %d\n", mydata.member1);
	mydata.member2 = 20.0F;
	printf("value of union: %f\n", mydata.member2);
	strncpy(mydata.member3, "hello", MAX_LENGTH);
	printf("value of union: %s\n", mydata.member3);
}
