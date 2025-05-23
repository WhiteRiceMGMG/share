#include <stdio.h>
#include "calc.h"

int main(void) {
    struct Calc calc;
    printf("PLEASE SUBSTITUTE THE COEFFICIENT WHEN ax^2 + bx + c = 0.\n");
    printf("ENTER COEFFICIENT -> ");
    scanf("%f %f %f", &calc.a, &calc.b, &calc.c);

    calcation(&calc);
    return 0;
}
