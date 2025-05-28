/*
#ifndef PARSER_H
#define PARSER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR
} TokenType;

struct Token {
    TokenType type;
    double value; // TOKEN_NUMBER用
    char op;      // TOKEN_OPERATOR用
};

int tokenize(const char* input, struct Token* tokens);


#endif
*/

#ifndef PARSER_H
#define PARSER_H

struct enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR
};

struct Token {
    TokenType type;
    double value;
    char op;
};

int tokenize (const char* input, struct Token* tokens);

#endif