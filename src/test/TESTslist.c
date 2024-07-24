#include "TEST.h"
#include "slist.h"

void TEST_slist(void){
    Slist slistH;
    SlistStatus status;
    int value;

    status = Slist_init( &slistH );

    status = Slist_remove( &slistH, 0 );

    status = Slist_pop( slistH, value );
    status = Slist_insert( &slistH, 0, 16 );
    status = Slist_insert( &slistH, 0, 17 );
    status = Slist_insert( &slistH, -1, 18 );
    status = Slist_insert( &slistH, -1, 19 );
    status = Slist_insert( &slistH, 0, 20 );
    status = Slist_insert( &slistH, -4, 20 );
    status = Slist_insert( &slistH, 1, 21 );
    status = Slist_insert( &slistH, 4, 22 );
    status = Slist_insert( &slistH, 20, 23 );

    status = Slist_append( slistH, 66 );
    status = Slist_preppend( slistH, 99 );
    status = Slist_pop( slistH, value );
    status = Slist_popFront( slistH, value );

    status = Slist_getIndex( &slistH, -4, &value );
    status = Slist_getIndex( &slistH, 0, &value );
    status = Slist_getIndex( &slistH, -1, &value );
    status = Slist_getIndex( &slistH, 4, &value );
    status = Slist_getIndex( &slistH, 40, &value );

    status = Slist_remove( &slistH, 0 );
    status = Slist_remove( &slistH, -1 );
    status = Slist_remove( &slistH, 3 );
    status = Slist_remove( &slistH, 50 );
    status = Slist_remove( &slistH, 50 );
    status = Slist_getIndex( &slistH, -1, &value );
    status = Slist_remove( &slistH, 50 );
    status = Slist_remove( &slistH, 50 );
    status = Slist_getIndex( &slistH, -1, &value );
    status = Slist_remove( &slistH, 50 );
    status = Slist_getIndex( &slistH, 0, &value );
    status = Slist_remove( &slistH, 0 );
    status = Slist_remove( &slistH, 3 );
    status = Slist_getIndex( &slistH, 0, &value );

    Slist_free(&slistH);
}
