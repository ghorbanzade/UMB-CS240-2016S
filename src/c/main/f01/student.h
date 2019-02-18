/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
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
