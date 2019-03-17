/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include "student-enum.h"

int main(void)
{
	struct student std;
	std.name = "John Smith";
	std.gpa = 3.45;
	std.year = FRESHMAN;
	show_info(&std);
}

void show_info(struct student *std)
{
	char *years[] = {"freshman", "sophomore", "junior", "senior"};
	printf("student name: %s\n", std->name);
	printf("student gpa:  %f\n", std->gpa);
	printf("student year: %s\n", years[std->year]);
}
