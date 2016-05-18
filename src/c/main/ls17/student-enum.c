/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
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
