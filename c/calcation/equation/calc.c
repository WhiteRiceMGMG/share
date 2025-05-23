#include <stdio.h>
#include "calc.h"

void calcation(struct Calc *calc) {
    if (calc->a == 0) {
        printf("IF a = 0, THE EQUATION CAN'T BE SOLVED.\n");
        return;
    }

    double result = -(double)(calc->b) / calc->a;
    printf("ANSWER = %.5f\n", result);
}
