#include "slist.h"

list listH;

int main(void)
{
    list_init(&listH);

    list_prepend(&listH, 16);   //[ 16 ]
    list_append(&listH, 32);    //[ 16 32 ]
    list_prepend(&listH, 18);   //[ 18 16 32 ]
    list_append(&listH, 32);    //[ 18 16 32 32 ]
    list_append(&listH, 64);    //[ 18 16 32 32 64 ]

    list_print(&listH);

    list_insert(&listH, 0, 99);     //[ 99 18 16 32 32 64 ]
    list_insert(&listH, 1, 55);     //[ 99 55 18 16 32 32 64 ]
    list_insert(&listH, 3, 66);     //[ 99 55 18 66 16 32 32 64 ]
    list_insert(&listH, 9, 299);    //[ 99 55 18 66 16 32 32 64 299]
    list_insert(&listH, 8, 699);    //[ 99 55 18 66 16 32 32 64 699 299]
    list_print(&listH);

    list_free(&listH);

    return 0;
}