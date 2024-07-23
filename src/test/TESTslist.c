#include "TEST.h"
#include "slist.h"

void slist_test(void){
    slist slistH;

    printf("------------slist------------\n");
    slist_init(&slistH);

    slist_prepend(&slistH, 16);   //[ 16 ]
    slist_append(&slistH, 32);    //[ 16 32 ]
    slist_prepend(&slistH, 18);   //[ 18 16 32 ]
    slist_append(&slistH, 32);    //[ 18 16 32 32 ]
    slist_append(&slistH, 64);    //[ 18 16 32 32 64 ]

    slist_print(&slistH);

    slist_insert(&slistH, 0, 99);     //[ 99 18 16 32 32 64 ]
    slist_insert(&slistH, 1, 55);     //[ 99 55 18 16 32 32 64 ]
    slist_insert(&slistH, 3, 66);     //[ 99 55 18 66 16 32 32 64 ]
    slist_insert(&slistH, 9, 299);    //[ 99 55 18 66 16 32 32 64 299]
    slist_insert(&slistH, 8, 699);    //[ 99 55 18 66 16 32 32 64 699 299]
    
    slist_print(&slistH);

    slist_remove(&slistH, 0);         //[ 55 18 66 16 32 32 64 699 299]
    slist_remove(&slistH, 2);         //[ 55 18 16 32 32 64 699 299]
    slist_remove(&slistH, 40);        //[ 55 18 16 32 32 64 699 ]
    slist_remove(&slistH, 40);        //[ 55 18 16 32 32 64 ]
    slist_remove(&slistH, 4);         //[ 55 18 16 32 64 ]

    slist_print(&slistH);

    slist_free(&slistH);
}
