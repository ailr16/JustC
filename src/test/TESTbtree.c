#include "btree.h"

void TEST_btree(void){
    Btree bH;

    Btree_init( &bH );

    Btree_insert( &bH, 16 );
    Btree_insert( &bH, 12 );
    Btree_insert( &bH, 8 );
    Btree_insert( &bH, 14 );
    Btree_insert( &bH, 18 );

    Btree_printPreorder( &bH );
    Btree_printInorder( &bH );
    Btree_printPostorder( &bH );

    Btree_destroy( &bH );
}