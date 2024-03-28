#include <stdio.h>

#include "dlist.h"

list_element a = {
    .data = 10,
    .list = LIST_HEAD_INIT( a.list )
};

int main(void)
{
    list_element b;
    b.data = 20;

    INIT_LIST_HEAD( &b.list );
    printf( "%d\n", a.data );
    printf( "%d\n", b.data );
    return 0;
}