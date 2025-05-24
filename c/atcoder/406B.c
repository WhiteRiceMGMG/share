#include <stdio.h>

int main(void) {
    int n = 0;
    int k = 0;
    int i = 0;
    long long ansArray[104];

    scanf("%d %d", &n, &k);

    long long max = 1;
    for (i = 1; i <= k; i++) {
        max = max * 10;
    }

    // 初期値は1とする
    ansArray[0] = 1;

    long long input;
    for (i = 0; i < n; i++) {
        scanf("%lld", &input);
        ansArray[i + 1] = ansArray[i] * input;

        if (ansArray[i + 1] >= max) {
            ansArray[i + 1] = 1;
        }
    }

    printf("%lld\n", ansArray[n]);  // n回目の操作後の値
    return 0;
}
