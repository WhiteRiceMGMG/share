#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 0;
    int k = 0;
    int n = 0;
    int l = 0;
    int countTilda = 0;
    int baseArray[300000] = {0};
    int tempArray[300000] = {0};

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &baseArray[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = 4; j <= n - i; j++) {
            int countSmall = 0;
            int countBig = 0;

            for(k = 0; k < j; k++) {
                tempArray[k] = baseArray[i + k];
            }

            if (tempArray[0] >= tempArray[1]) {
                continue;  // 条件1: A1 < A2 を満たさない
            }

            for(l = 1; l < j - 1; l++) {
                if((tempArray[l] < tempArray[l-1]) && (tempArray[l] < tempArray[l+1])) {
                    countSmall++;
                } else if ((tempArray[l] > tempArray[l-1]) && (tempArray[l] > tempArray[l+1])) {
                    countBig++;
                }
            }

            if((countSmall == 1) && (countBig == 1)) {
                countTilda++;
            }
        }
    }

    printf("%d\n", countTilda);
    return 0;
}
