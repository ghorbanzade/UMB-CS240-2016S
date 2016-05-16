/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
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
		strncpy(basket[i], fruits[i], sizeof(fruits[i]));
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
