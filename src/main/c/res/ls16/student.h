/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>

#define MAXLEN 16

struct student {
	int id;
	float gpa;
	char name[MAXLEN];
};

#endif // STUDENT_H
