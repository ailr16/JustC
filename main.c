#include "dlist.h"
#include "slist.h"
#include "rbuffer.h"

void slist_test(void);
void dlist_test(void);

#define BUFFER_SIZE 6

int a[BUFFER_SIZE];

rbuffer buffer1 = {
    .array = a,
};

int main(void)
{   
    rbufferStatus status = RBUFFER_OK;
    int getted = 0;

    rbuffer_init( &buffer1, BUFFER_SIZE);   //_ _ _ _ _ _

    status = rbuffer_put( &buffer1, 1 );
    status = rbuffer_put( &buffer1, 2 );
    status = rbuffer_put( &buffer1, 4 );
    status = rbuffer_put( &buffer1, 8 );
    status = rbuffer_put( &buffer1, 16 );
    status = rbuffer_put( &buffer1, 32 );
    status = rbuffer_put( &buffer1, 64 );

    status = rbuffer_get( &buffer1, &getted );
    status = rbuffer_get( &buffer1, &getted );
    status = rbuffer_get( &buffer1, &getted );

    status = rbuffer_put( &buffer1, 64 );
    status = rbuffer_get( &buffer1, &getted );
    status = rbuffer_get( &buffer1, &getted );
    status = rbuffer_get( &buffer1, &getted );
    status = rbuffer_get( &buffer1, &getted );
    status = rbuffer_get( &buffer1, &getted );
    status = rbuffer_put( &buffer1, 128 );
    status = rbuffer_get( &buffer1, &getted );

    status = rbuffer_flush( &buffer1 );

    return 0;
}

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

void dlist_test(void){
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