/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
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
