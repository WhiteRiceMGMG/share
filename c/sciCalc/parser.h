#ifndef PARSER_H
#define PARSER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR
} TokenType;

typedef struct {
    TokenType type;
    double value; // TOKEN_NUMBER用
    char op;      // TOKEN_OPERATOR用
} Token;

int tokenize(const char* input,  Token* tokens);


#endif
