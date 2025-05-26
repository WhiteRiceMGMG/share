#include <stdio.h>
#define MAX_N 100
#define MAX_H 10
#define MAX_W 10
#define MAX_R 10
#define MAX_C 10

int main(void){
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);
    static char stamps[MAX_N][MAX_H][MAX_W+1];
    for(int k = 0; k < N; k++){
        for(int i = 0; i < H; i++){
            scanf("%s", stamps[k][i]);
        }
    }

    int R, C;
    scanf("%d %d", &R, &C);
    static int B[MAX_R][MAX_C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%d", &B[i][j]);
            B[i][j]--;  // 0-based
        }
    }

    // 出力
    for(int br = 0; br < R; br++){
        for(int si = 0; si < H; si++){
            for(int bc = 0; bc < C; bc++){
                int idx = B[br][bc];
                printf("%s", stamps[idx][si]);
            }
            putchar('\n');
        }
    }
    return 0;
}
