/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <stdio.h>

int main(void)
{
	char letter = 'Q';
	short num_students = 64;
	int income = 124350;
	long population = 2238643747;
	float height = 19.75;
	double avogadro = 6.022e23;
	printf("%c\n", letter);
	printf("%d\n", num_students);
	printf("%d\n", income);
	printf("%ld\n", population);
	printf("%f\n", height);
	printf("%e\n", avogadro);
}
