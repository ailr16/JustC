#include <stdio.h>
#include "including.h"

#define SQR(n) (n)*(n)

int main(void){
    printf("Square of %d is: %d\n", 2+3, SQR(2+3));
    
    return 0;
}