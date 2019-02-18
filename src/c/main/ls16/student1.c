/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "student.h"

int main(void)
{
	struct student std;
	std.id = 1234;
	std.gpa = 3.45;
	strncpy(std.name, "John Smith", MAXLEN);
	printf("student id:   %d\n", std.id);
	printf("student name: %s\n", std.name);
	printf("student gpa:  %f\n", std.gpa);
}
