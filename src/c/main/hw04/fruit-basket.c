/**
 * UMB-CS240-2016S: Programming in C
 * Copyright 2016 Pejman Ghorbanzade <pejman@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 */




#include "fruit-basket.h"

/**
 * fills a basket with fruits and prints their name.
 */
int main(void)
{
	char *basket[BASKET_SIZE];
	fill_basket(basket, BASKET_SIZE);
	show_basket(basket, BASKET_SIZE);
}

/**
 * fills basket with banana, apple, orange, pineapple
 */
void fill_basket(char *basket[], const int size)
{
	int i;
	char *fruits[] = {"banana", "apple", "orange", "pineapple"};
	for (i = 0; i < size; i++) {
		basket[i] = malloc(sizeof(fruits[i]));
		strncpy(basket[i], fruits[i], (int) sizeof(fruits[i]));
	}
}

/**
 * prints contents of a given basket
 */
void show_basket(char *basket[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("fruit %d: %s\n", i + 1, basket[i]);
	}
}
