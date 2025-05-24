#include <stdio.h>
#include <stdlib.h>

#define MAX_N 300000

typedef struct {
    char symbol;    // '<' または '>'
    long long count; // 連続数
} Run;

int P[MAX_N];
Run runs[MAX_N];
int run_len = 0;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    // ランレングス圧縮
    for (int i = 0; i < n - 1; i++) {
        char c = (P[i] < P[i + 1]) ? '<' : '>';
        if (run_len == 0 || runs[run_len - 1].symbol != c) {
            runs[run_len].symbol = c;
            runs[run_len].count = 1;
            run_len++;
        } else {
            runs[run_len - 1].count++;
        }
    }

    // 中央が '>' で、左右が '<' の形を探す
    long long ans = 0;
    for (int i = 1; i < run_len - 1; i++) {
        if (runs[i].symbol == '>') {
            ans += runs[i - 1].count * runs[i + 1].count;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
