#include "TEST.h"
#include "slist.h"
#include "algos.h"

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

    // Search algorithm

    Slist_print( &slistH );

    uint32_t resultIndex = 0;
    status = Search_item( (void*)&slistH, SLIST_T, 16, &resultIndex );
    if(status == SLIST_OK)
        printf("Index of first [%d] occurrence: %d\n", 16, resultIndex );

    status = Search_item( (void*)&slistH, SLIST_T, 23, &resultIndex );
    if(status == SLIST_OK)
        printf("Index of first [%d] occurrence: %d\n", 23, resultIndex );

    status = Search_item( (void*)&slistH, SLIST_T, 20, &resultIndex );
    if(status == SLIST_OK)
        printf("Index of first [%d] occurrence: %d\n", 20, resultIndex );

    status = Search_item( (void*)&slistH, SLIST_T, 900, &resultIndex );
    if(status == SLIST_OK)
        printf("Index of first [%d] occurrence: %d\n", 900, resultIndex );

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
