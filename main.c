#include <stdio.h>

#include "slist.h"

int num = 5;

list_element a;

int main(void)
{
    a.data = &num;
    printf( "%d\n", sizeof(a) );
    printf( "%d\n", *(int*)a.data );
    return 0;
}