#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printOdds() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            printf("Odd: %d\n", i);
        }
    }
}

void printEvens() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("Even: %d\n", i);
        }
    }
}
