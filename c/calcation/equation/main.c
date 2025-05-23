#include <stdio.h>
#include "calc.h"

int main(void) {
    struct Calc calc;

    printf("PLEASE SUBSTITUTE THE COEFFICIENT WHEN ax + b = 0.\n");
    printf("ENTER COEFFICIENT -> ");
    scanf("%d %d", &calc.a, &calc.b);

    // 計算実行＋表示
    calcation(&calc);

    return 0;
}
