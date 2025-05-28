// evaluator.c（シンプルな左から計算バージョン）
#include <stdio.h>
#include "evaluator.h"

double evaluate(Token* tokens) {
    double result = 0;
    Token* tok = tokens;

    if (tok->type != TOKEN_NUMBER) {
        printf("数値で始まっていません\n");
        return 0;
    }

    result = tok->value;
    tok++;

    while (tok->type != TOKEN_END) {
        char op = tok->op;
        tok++;
        if (tok->type != TOKEN_NUMBER) {
            printf("演算子の後に数値が必要です\n");
            return 0;
        }

        double num = tok->value;

        switch (op) {
            case '+': result += num; break;
            case '-': result -= num; break;
            case '*': result *= num; break;
            case '/': result /= num; break;
            default:
                printf("未知の演算子: %c\n", op);
                return 0;
        }

        tok++;
    }

    return result;
}
