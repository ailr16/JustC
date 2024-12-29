#include "TEST.h"
#include "dlist.h"
#include "algos.h"

void TEST_dlist(void){
    Dlist dlistH;
    DlistStatus status;
    int outValue;

    printf("--------------------\n");
    printf("Double linked list test\n");

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


    // Search algorithm

    uint32_t *resultIndex = NULL;
    uint32_t resultSize = 0;

    status = Search_item( &dlistH, DLIST_T, 16, &resultIndex, &resultSize );
    if(status == DLIST_OK){
        printf("Searching for 16: [ ");
        for( uint32_t i = 0; i < resultSize; i++)
            printf( "%d ", resultIndex[i] );
        printf("]\n");
    }

    status = Search_item( &dlistH, DLIST_T, 22, &resultIndex, &resultSize );
    if(status == DLIST_OK){
        printf("Searching for 22: [ ");
        for( uint32_t i = 0; i < resultSize; i++)
            printf( "%d ", resultIndex[i] );
        printf("]\n");
    }

    status = Search_item( &dlistH, DLIST_T, 900, &resultIndex, &resultSize );
    if(status == DLIST_OK){
        printf("Searching for 900: [ ");
        for( uint32_t i = 0; i < resultSize; i++)
            printf( "%d ", resultIndex[i] );
        printf("]\n");
    }

    status = DLIST_APPEND( dlistH, 16 );
    Dlist_print( &dlistH );

    status = Search_item( &dlistH, DLIST_T, 16, &resultIndex, &resultSize );
    if(status == DLIST_OK){
        printf("Searching for 16: [ ");
        for( uint32_t i = 0; i < resultSize; i++)
            printf( "%d ", resultIndex[i] );
        printf("]\n");
    }

    free( resultIndex );

    // Sum elements algo

    uint32_t resultSum = 0;

    Dlist_print( &dlistH );
    status = Sum_elements( &dlistH, DLIST_T, &resultSum );
    printf("Sum=%d\n", resultSum );

    int data;

    status = Dlist_remove( &dlistH, -3, &data );
    status = Dlist_remove( &dlistH, 0, &data );
    status = Dlist_remove( &dlistH, -1, &data);
    status = Dlist_remove( &dlistH, 2, &data );
    status = Dlist_remove( &dlistH, 3, &data );
    status = Dlist_remove( &dlistH, 1, &data );
    status = Dlist_remove( &dlistH, 2, &data );

    Dlist_free( &dlistH );
    printf("--------------------\n");
}
