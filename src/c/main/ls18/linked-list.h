/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* next;
	int value;
};
