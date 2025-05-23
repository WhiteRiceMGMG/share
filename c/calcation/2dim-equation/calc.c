#include <stdio.h>
#include <math.h>
#include "calc.h"

void calcation(struct Calc *calc) {
    if (calc->a == 0 && calc->b != 0) {
        float result = -(calc->c) / calc->b;
        printf("%.5f\n", result);
    }
    else if (calc->b == 0 && calc->a != 0) {
        if ((calc->c / calc->a) < 0) {
            printf("No real solution.\n");
        } else {
            float result = -sqrt(calc->c / calc->a);
            printf("%.5f\n", result);
        }
    }
    else if (calc->a == 0 && calc->b == 0) {
        printf("CAUTION!! IF A=0,B=0, NOT SOLVE \n");
    }
    else {
        float discriminant = calc->b * calc->b - 4.0f * calc->a * calc->c;  
        if (discriminant < 0) {
            printf("No real roots.\n");
        } else {
            float root1 = (-calc->b + sqrt(discriminant)) / (2.0f * calc->a);
            float root2 = (-calc->b - sqrt(discriminant)) / (2.0f * calc->a);
            printf("%.5f %.5f\n", root1, root2);
        }
    }
}
