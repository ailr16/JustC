#include "TEST.h"
#include "dlist.h"

void TEST_dlist(void){
    Dlist dlistH;
    DlistStatus status;

    Dlist_init( &dlistH );

    status = Dlist_insert( &dlistH, -4, 16 );
    status = Dlist_insert( &dlistH, 0, 16 );
    status = Dlist_insert( &dlistH, 0, 17 );
    status = Dlist_insert( &dlistH, -1, 18 );
    status = Dlist_insert( &dlistH, -1, 19 );
    status = Dlist_insert( &dlistH, 0, 20 );
    status = Dlist_insert( &dlistH, 1, 21 );
    status = Dlist_insert( &dlistH, 4, 22 );
    status = Dlist_insert( &dlistH, 40, 22 );

    Dlist_print( &dlistH );

    int data;

    status = Dlist_remove( &dlistH, -3, &data );
    status = Dlist_remove( &dlistH, 0, &data );
    status = Dlist_remove( &dlistH, -1, &data);
    status = Dlist_remove( &dlistH, 2, &data );
    status = Dlist_remove( &dlistH, 3, &data );
    status = Dlist_remove( &dlistH, 1, &data );
    status = Dlist_remove( &dlistH, 2, &data );

    Dlist_free( &dlistH );
}