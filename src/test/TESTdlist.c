#include "TEST.h"
#include "dlist.h"

void TEST_dlist(void){
    Dlist dlistH;
    DlistStatus status;
    int outValue;

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

    status = DLIST_APPEND( dlistH, 32 );
    status = DLIST_PREPEND( dlistH, 128 );
    status = DLIST_PREPEND( dlistH, 128 );
    Dlist_print( &dlistH );
    status = DLIST_POPFRONT( dlistH, outValue );
    status = DLIST_POP( dlistH, outValue );

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