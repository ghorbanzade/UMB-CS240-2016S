/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include "student.h"

void init(struct student *std);
void display(struct student *std);

int main(void)
{
	struct student jsmith;
	init(&jsmith);
	display(&jsmith);
}

void init(struct student *std)
{
	std->id = 1234;
	std->gpa = 3.45;
	strncpy(std->name, "John Smith", MAXLEN);
}

void display(struct student *std)
{
	printf("student id:   %d\n", std->id);
	printf("student name: %s\n", std->name);
	printf("student gpa:  %f\n", std->gpa);
}
