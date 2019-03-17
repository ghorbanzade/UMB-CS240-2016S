/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#include "student.h"

int main(void)
{
	float avg;
	struct student std[3];
	std[0] = init("alex", 3.6, 2015);
	std[1] = init("bill", 4.0, 2015);
	std[2] = init("cindy", 2.0, 2015);
	avg = average_gpa(&std[0], 3, 2015);
	printf("average gpa: %.2f\n", avg);
}

/**
 * creates a student structure based on given data for a student.
 */
struct student init(char *name, float gpa, int year)
{
	struct student std;
	std.name = name;
	std.gpa = gpa;
	std.year = year;
	return std;
}

/**
 * takes a list of students and a graduation year and returns the average
 * gpa of students graduating in that given year.
 */
float average_gpa(struct student *std, int size, int year)
{
	int i;
	int count = 0;
	float sum = 0;
	for (i = 0; i < size; i++) {
		if (std[i].year == year) {
			count++;
			sum += std[i].gpa;
		}
	}
	return sum / count;
}
