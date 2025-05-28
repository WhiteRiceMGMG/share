/*
1. ユーザーから文字列入力
2. `tokenize()` を呼び出してトークン列に変換
3. `evaluate()` を呼び出して数値結果を得る
4. 結果を表示
5. メモリ解放
*/

#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "evaluator.h"

int main() {
    char input[256];
    double result = 0;

    printf("関数電卓 v0.1\n");
    printf("> ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 

    Token* tokens = tokenize(input);
    result = evaluate(tokens);
    printf("= %f\n", result);

    free_tokens(tokens);
    return 0;
}
