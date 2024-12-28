#include "TEST.h"
#include "slist.h"

void TEST_slist(void){
    Slist slistH;
    SlistStatus status;
    int value;

    printf("--------------------\n");
    printf("Single linked list test\n");

    status = Slist_init( &slistH );

    status = Slist_remove( &slistH, 0 );

    status = SLIST_POP( slistH, value );
    status = Slist_insert( &slistH, 0, 16 );
    status = Slist_insert( &slistH, 0, 17 );
    status = Slist_insert( &slistH, -1, 18 );
    status = Slist_insert( &slistH, -1, 19 );
    status = Slist_insert( &slistH, 0, 20 );
    status = Slist_insert( &slistH, -4, 20 );
    status = Slist_insert( &slistH, 1, 21 );
    status = Slist_insert( &slistH, 4, 22 );
    status = Slist_insert( &slistH, 20, 23 );

    Slist_print( &slistH );

    status = SLIST_APPEND( slistH, 66 );
    status = SLIST_PREPEND( slistH, 99 );
    status = SLIST_POP( slistH, value );
    status = SLIST_POPFRONT( slistH, value );

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

    printf("--------------------\n");
}
