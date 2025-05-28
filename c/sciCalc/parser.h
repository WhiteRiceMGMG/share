// parser.h
#ifndef PARSER_H
#define PARSER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    double value;  // TOKEN_NUMBER用
    char op;       // TOKEN_OPERATOR用
} Token;

Token* tokenize(const char* input); // 入力文字列 → トークン配列
void free_tokens(Token* tokens);    // メモリ解放

#endif
