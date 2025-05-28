/*
#include <stdio.h>
#include "parser.h"
#include "evaluator.h"

int main(void) {
    char input[100];
    printf("式を入力してください（例: 3 + 4）: ");
    fgets(input, sizeof(input), stdin);

    Token tokens[3];
    int token_count = tokenize(input, tokens);

    double result = evaluate(tokens, token_count);

    printf("答え: %lf\n", result);
    return 0;
}
*/
#include <stdio.h>
#include "parser.h"
#include "evaluator.h"

#define MAX 63

int main(void) {
    char input[MAX + 1] = "";
    printf("数式を入力してください：");
    fgets(input,sizeof(input),stdin);

    struct Token tokens[3];
    int token_count = tokenize(input, tokens);
    double result = evaluate(tokens, token_count);
    
    printf("答え：%lf\n", result);
    return 0;
}