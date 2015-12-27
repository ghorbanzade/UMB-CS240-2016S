/**
 * CS240: Programming in C
 * Copyleft 2016 Pejman Ghorbanzade <mail@ghorbanzade.com>
 * More info: https://github.com/ghorbanzade/UMB-CS240-2016S
 *
 * The author has placed this file in the public domain.
 * He makes no warranty and accepts no liability for this file.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        printf("%s is %s today!\n", argv[1], argv[2]);
    } else {
        printf("Error: insufficient number of arguments\n");
    }
}
