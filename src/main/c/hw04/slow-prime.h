/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
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
