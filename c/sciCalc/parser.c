// parser.c（抜粋）
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parser.h"

#define MAX_TOKENS 128

Token* tokenize(const char* input) {
    Token* tokens = malloc(sizeof(Token) * MAX_TOKENS);
    int pos = 0;

    for (int i = 0; input[i] != '\0'; ) {
        if (isspace(input[i])) {
            i++;
        } else if (isdigit(input[i]) || input[i] == '.') {
            char numbuf[32] = {0};
            int j = 0;
            while (isdigit(input[i]) || input[i] == '.') {
                numbuf[j++] = input[i++];
            }
            tokens[pos].type = TOKEN_NUMBER;
            tokens[pos].value = atof(numbuf);
            pos++;
        } else if (strchr("+-*/", input[i])) {
            tokens[pos].type = TOKEN_OPERATOR;
            tokens[pos].op = input[i++];
            pos++;
        } else {
            printf("未知の文字: %c\n", input[i]);
            exit(1);
        }
    }

    tokens[pos].type = TOKEN_END; // 終了トークン
    return tokens;
}

void free_tokens(Token* tokens) {
    free(tokens);
}
