#include <stdio.h>

#define MAX 1003

int main(void) {
  float n = 0;
  float s = 0;
  int i = 0;
  int flag = 0; // 1なら寝た
  int array[MAX + 1];
  
  // 入力
  scanf("%f %f", &n, &s);
  for(i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // 最初の肩叩きまでに寝てしまうかチェック
  if(array[0] >= s + 0.5f) {
    flag = 1;
  }

  // 各肩叩きの間隔をチェック
  for(i = 1; i < n; i++) {
    if(array[i] - array[i-1] >= s + 0.5f) {
      flag = 1;
      break;
    }
  }

  // 結果出力
  if(flag == 1) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }

  return 0;
}
