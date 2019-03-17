/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#ifndef FAST_PRIME_H
#define FAST_PRIME_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME_LIST "primes.log"
#define LINE_WIDTH 32

int str2int(char *str, int *num);
int prime_check(int num);
int read_primes(int **primes, int *size);
int check_on_set(int num, int *primes, int size);
int check_beyond(int num, int **primes, int *size);
int get_alloc_size(int size);
int write_primes(int *primes, int primes_size);

#endif // FAST_PRIME_H
