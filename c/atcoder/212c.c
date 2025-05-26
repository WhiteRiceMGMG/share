#include <stdio.h>
#include <stdlib.h>

// 比較関数（qsort用）
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 絶対値を返す関数（if-elseで可読性アップ）
int abs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int main(void) {
    int n, m;

    // 入力：2つの数列の長さ
    scanf("%d %d", &n, &m);

    // メモリ確保
    int *A = (int *)malloc(sizeof(int) * n);
    int *B = (int *)malloc(sizeof(int) * m);

    // 数列Aの入力
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // 数列Bの入力
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    // 数列A, Bをそれぞれ昇順にソート
    qsort(A, n, sizeof(int), compare);
    qsort(B, m, sizeof(int), compare);

    // ポインタi, jを0からスタート
    int i = 0;
    int j = 0;

    // 最小値を非常に大きな値で初期化
    int minDiff = 1000000000;

    // 2つの配列の末尾までポインタを進める
    while (i < n && j < m) {
        int diff = abs(A[i] - B[j]);

        // 最小値の更新
        if (diff < minDiff) {
            minDiff = diff;
        }

        // 小さい方のポインタを進める
        if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }

    // 結果出力
    printf("%d\n", minDiff);

    // メモリ解放
    free(A);
    free(B);

    return 0;
}