/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

struct student {
	char *name;
	float gpa;
	int year;
};

struct student init(char *name, float gpa, int year);
float average_gpa(struct student *std, int size, int year);

#endif // STUDENT_H
