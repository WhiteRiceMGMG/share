#include <stdio.h>

int main() {
    int arr2[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    int *ptr;

    ptr = *arr2;

    ptr = &arr2[0][0];

    int (*ptr2)[3] = arr2;
    // int *ptr2[3] はエラー
    int(* ptr3)[3] =  arr2;
    return 0;

}
