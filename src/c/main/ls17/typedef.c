/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include "typedef.h"

int main(void)
{
	Student std;
	std.id = 1234;
	std.gpa = 3.45;
	strncpy(std.name, "John Smith", MAXLEN);
	show(&std);
}

void show(Student *std)
{
	printf("student id:   %d\n", std->id);
	printf("student name: %s\n", std->name);
	printf("student gpa:  %f\n", std->gpa);
}
