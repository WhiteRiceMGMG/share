#include <stdio.h>

int main(void) {
    int array[4];
    int i = 0;
    int weakFlag = 0;
    char tempStr[5];

    scanf("%s", tempStr);
    for(i = 0; i < 4; i++) {
        array[i] = tempStr[i] - '0';
    }
    
    
    for(i = 0; i < 3; i++) {
        if(array[i] == array[i + 1]) {
            weakFlag = 1;
            continue;
        }
        weakFlag = 0;
        break;
    }
    if(weakFlag == 1) {
        printf("Weak");
        return 0;
    }

    for(i = 0; i < 3; i++) {
        if(array[i+1] == array[i] + 1) {
            weakFlag = 1;
            continue;
        } else if((array[i] == 9) && (array[i+1] == 0)) {
            weakFlag = 1;
            continue;
        }
        weakFlag = 0;
        break;
    }
    if(weakFlag == 1) {
        printf("Weak");
    } else {
        printf("Strong");
    }    
}