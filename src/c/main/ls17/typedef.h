/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <stdio.h>
#include <string.h>

#define MAXLEN 16

typedef struct student {
	int id;
	float gpa;
	char name[MAXLEN];
} Student;

void show(Student *std);

#endif // TYPEDEF_H
