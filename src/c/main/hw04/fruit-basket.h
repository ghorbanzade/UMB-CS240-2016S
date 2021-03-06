/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#ifndef FRUIT_BASKET_H
#define FRUIT_BASKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASKET_SIZE 4

void fill_basket(char *basket[], int size);
void show_basket(char *basket[], int size);

#endif // FRUIT_BASKET_H
