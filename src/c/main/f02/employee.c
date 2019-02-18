/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>
#include <stdlib.h>

struct employee {
	int id;
	char *name;
	int hours;
	enum {
		FULLTIME,
		PARTTIME,
		INTERN,
		COUNT
	} status;
};

struct employee init(int id, char *name, int hours, int status)
{
	struct employee emp;
	emp.id = id;
	emp.name = name;
	emp.hours = hours;
	emp.status = status;
	return emp;
}

float find_payroll(struct employee emp)
{
	if (emp.status == FULLTIME)
		return 800.0;
	else if (emp.status == PARTTIME)
		return emp.hours * 4.0;
	else if (emp.status == INTERN)
		return emp.hours * 2.0;
	abort();
}

float find_payroll_total(struct employee *emps, int count)
{
	int i;
	float sum = 0;
	for (i = 0; i < count; i++)
		sum += find_payroll(emps[i]);
	return sum;
}

int main(void)
{
	float pay, total;
	struct employee emp;
	struct employee emps[3];
	emp = init(1, "Ron", 100, FULLTIME);
	emps[0] = emp;
	emps[1] = init(2, "Fred", 140, PARTTIME);
	emps[2] = init(3, "George", 160, INTERN);
	pay = find_payroll(emp);
	total = find_payroll_total(emps, 3);
	printf("Ron's Payroll: %.2f\n", pay);
	printf("Total Amount: %.2f\n", total);
}
