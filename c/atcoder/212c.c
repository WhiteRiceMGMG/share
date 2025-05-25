/*それぞれN個，M個の2つの数列が与えられる．それぞれの数列から1つずつ要素を選んだ時の2つの値の差の最小値を求めてください．*/

#include <stdio.h>

int main(void) {
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    long min = 100000000;
    long tempMin = 100000000;

    scanf("%d %d",&n, &m);
    int arrayA[n];
    int arrayB[m];

    for(i = 0; i < n; i++) {
        scanf("%d", &arrayA[i]);
    }
    
    for(j = 0; j < m; j++) {
        scanf("%d", &arrayB[j]);
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            tempMin = arrayA[i] - arrayB[j];
            if(tempMin < 0) {
                tempMin = tempMin * (-1);
                }
            if(tempMin < min) {
                min = tempMin;
            }
        }
    }

    printf("%ld", min);

    return 0;
}


