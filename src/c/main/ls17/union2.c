/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
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
	mydata.member2 = 20.0F;
	strncpy(mydata.member3, "hello", MAX_LENGTH);
	printf("value of union: %d\n", mydata.member1);
	printf("value of union: %f\n", mydata.member2);
	printf("value of union: %s\n", mydata.member3);
}
