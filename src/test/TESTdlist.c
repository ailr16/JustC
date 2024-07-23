#include "TEST.h"
#include "dlist.h"

void TEST_dlist(void){
    dlist dlistH;

    printf("\n------------dlist------------\n");
    dlist_init(&dlistH);

    dlist_prepend(&dlistH, 16);   //[ 16 ]
    dlist_append(&dlistH, 32);    //[ 16 32 ]
    dlist_prepend(&dlistH, 18);   //[ 18 16 32 ]
    dlist_append(&dlistH, 32);    //[ 18 16 32 32 ]
    dlist_append(&dlistH, 64);    //[ 18 16 32 32 64 ]

    dlist_print(&dlistH);

    dlist_insert(&dlistH, 0, 99);     //[ 99 18 16 32 32 64 ]
    dlist_insert(&dlistH, 1, 55);     //[ 99 55 18 16 32 32 64 ]
    dlist_insert(&dlistH, 3, 66);     //[ 99 55 18 66 16 32 32 64 ]
    dlist_insert(&dlistH, 9, 299);    //[ 99 55 18 66 16 32 32 64 299]
    dlist_insert(&dlistH, 8, 699);    //[ 99 55 18 66 16 32 32 64 699 299]
    dlist_print(&dlistH);

    dlist_remove(&dlistH, 0);         //[ 55 18 66 16 32 32 64 699 299]
    dlist_remove(&dlistH, 2);         //[ 55 18 16 32 32 64 699 299]
    dlist_remove(&dlistH, 40);        //[ 55 18 16 32 32 64 699 ]
    dlist_remove(&dlistH, 40);        //[ 55 18 16 32 32 64 ]
    dlist_remove(&dlistH, 4);         //[ 55 18 16 32 64 ]

    dlist_print(&dlistH);

    dlist_free(&dlistH);
}