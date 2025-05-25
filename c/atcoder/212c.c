/*それぞれN個，M個の2つの数列が与えられる．それぞれの数列から1つずつ要素を選んだ時の2つの値の差の最小値を求めてください．*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int *A = (int *)malloc(sizeof(int) * n);
    int *B = (int *)malloc(sizeof(int) * m);

    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);

    qsort(A, n, sizeof(int), compare);
    qsort(B, m, sizeof(int), compare);

    int i = 0, j = 0;
    int minDiff = 1000000000;

    while (i < n && j < m) {
        int diff = abs(A[i] - B[j]);
        if (diff < minDiff) minDiff = diff;

        if (A[i] < B[j]) i++;
        else j++;
    }

    printf("%d\n", minDiff);

    free(A);
    free(B);
    return 0;
}



/*
#include <stdio.h>

int main(void) {
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    int min = 100000000;
    int tempMin = 100000000;

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

    printf("%d", min);

    return 0;
}
*/

