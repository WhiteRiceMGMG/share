#include <stdio.h>

int main(void) {
    int array[4];
    int i = 0;
    int weakFlag = 0;
    for(i = 0; i < 4; i++) {
        scanf("%d", &array[i]);
    }
    for(i = 0; i < 3; i++) {
        if(array[i] == array[i + 1]) {
            weakFlag = 1;
            continue;
        }
        weakFlag = 0;
    }
    if(weakFlag == 1) {
        printf("Weak");
    }
    printf("outside");
}