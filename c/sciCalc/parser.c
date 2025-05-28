#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "parser.h"

int tokenize(const char* input, Token* tokens) {
    double num1, num2;
    char op;
    if (sscanf(input, "%lf %c %lf", &num1, &op, &num2) != 3) {
        printf("パースエラー\n");
        return 0;
    }

    tokens[0].type = TOKEN_NUMBER;
    tokens[0].value = num1;

    tokens[1].type = TOKEN_OPERATOR;
    tokens[1].op = op;

    tokens[2].type = TOKEN_NUMBER;
    tokens[2].value = num2;

    return 3;
}
