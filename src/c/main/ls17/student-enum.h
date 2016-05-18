/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#ifndef ENUM_H
#define ENUM_H

#include <stdio.h>

enum level {
	FRESHMAN,
	SOPHOMORE,
	JUNIOR,
	SENIOR
};

struct student {
	char *name;
	float gpa;
	enum level year;
};

void show_info(struct student *std);

#endif // ENUM_H
