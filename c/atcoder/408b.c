#include <stdio.h>

int main(void) {
  int n, i;
  int a[101];           // 元の配列
  int seen[101] = {0};  // 値が出たかどうかのフラグ配列
  int result[101];      // 重複を除いた結果格納用
  int count = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (!seen[a[i]]) {
      seen[a[i]] = 1;
    }
  }

  // seen配列から小さい順に出力
  for (i = 1; i <= 100; i++) {
    if (seen[i]) {
      result[count++] = i;
    }
  }

  printf("%d\n", count);
  for (i = 0; i < count; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");

  return 0;
}
