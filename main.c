#include "dlist.h"

dlist listH;

int main(void)
{
    dlist_init(&listH);

    dlist_prepend(&listH, 16);   //[ 16 ]
    dlist_append(&listH, 32);    //[ 16 32 ]
    dlist_prepend(&listH, 18);   //[ 18 16 32 ]
    dlist_append(&listH, 32);    //[ 18 16 32 32 ]
    dlist_append(&listH, 64);    //[ 18 16 32 32 64 ]

    dlist_print(&listH);

    dlist_insert(&listH, 0, 99);     //[ 99 18 16 32 32 64 ]
    dlist_insert(&listH, 1, 55);     //[ 99 55 18 16 32 32 64 ]
    dlist_insert(&listH, 3, 66);     //[ 99 55 18 66 16 32 32 64 ]
    dlist_insert(&listH, 9, 299);    //[ 99 55 18 66 16 32 32 64 299]
    dlist_insert(&listH, 8, 699);    //[ 99 55 18 66 16 32 32 64 699 299]
    dlist_print(&listH);

    dlist_free(&listH);
    /*

    dlist_remove(&listH, 0);         //[ 55 18 66 16 32 32 64 699 299]
    dlist_remove(&listH, 2);         //[ 55 18 16 32 32 64 699 299]
    dlist_remove(&listH, 40);        //[ 55 18 16 32 32 64 699 ]
    dlist_remove(&listH, 40);        //[ 55 18 16 32 32 64 ]
    dlist_remove(&listH, 4);         //[ 55 18 16 32 64 ]
    dlist_print(&listH);
    */
    return 0;
}