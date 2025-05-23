#include <stdio.h>

int main(void) {
  int A = 0;
  int B = 0;
  int C = 0;
  int D = 0;
  int i = 0;

  scanf("%d %d %d %d", &A, &B, &C, &D);
  if(A > C) {
    printf("Yes");
  } else { 
     if( A== C) {
       if ( B > D ) {
         printf("Yes");
       } else {
         printf("No");
       }
     } else {
       printf("No"); 
     }
  }
  
  return 0;
}

