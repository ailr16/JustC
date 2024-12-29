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
    status = SLIST_APPEND( slistH, 16 );
    status = SLIST_APPEND( slistH, 16 );
    status = SLIST_PREPEND( slistH, 16 );

    // Search algorithm

    Slist_print( &slistH );

    uint32_t *resultIndex = NULL;
    uint32_t resultSize = 0;

    status = Search_item( &slistH, SLIST_T, 16, &resultIndex, &resultSize );
    if(status == SLIST_OK){
        printf("[ ");
        for( uint32_t i = 0; i < resultSize; i++)
            printf( "%d ", resultIndex[i] );
        printf("]\n");
    }

    status = Search_item( &slistH, SLIST_T, 22, &resultIndex, &resultSize );
    if(status == SLIST_OK){
        printf("[ ");
        for( uint32_t i = 0; i < resultSize; i++)
            printf( "%d ", resultIndex[i] );
        printf("]\n");
    }

    status = Search_item( &slistH, SLIST_T, 900, &resultIndex, &resultSize );
    if(status == SLIST_OK){
        printf("[ ");
        for( uint32_t i = 0; i < resultSize; i++)
            printf( "%d ", resultIndex[i] );
        printf("]\n");
    }

    free( resultIndex );

    // Sum elements algo

    uint32_t resultSum = 0;

    Slist_print( &slistH );
    status = Sum_elements( &slistH, SLIST_T, &resultSum );
    printf("Sum=%d\n", resultSum );

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


    Slist_print( &slistH );

    Slist_free( &slistH );

    printf("--------------------\n");
}
