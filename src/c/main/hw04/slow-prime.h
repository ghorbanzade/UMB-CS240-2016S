/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */

#ifndef SLOW_PRIME_H
#define SLOW_PRIME_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int get_number(char *arg, int *num);
void next_prime(int num, int *nxt);
int is_prime(int num);

#endif // SLOW_PRIME_H
