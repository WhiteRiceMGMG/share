#include <stdio.h>
#include "evaluator.h"

double evaluate(Token* tokens, int token_count) {
    if (token_count != 3) {
        printf("トークン数が正しくありません\n");
        return 0.0;
    }

    double lhs = tokens[0].value;
    char op = tokens[1].op;
    double rhs = tokens[2].value;

    switch (op) {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '*': return lhs * rhs;
        case '/': return rhs != 0 ? lhs / rhs : 0.0;
        default:
            printf("未知の演算子です\n");
            return 0.0;
    }
}
