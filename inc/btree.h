#ifndef BTREE_H
#define BTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef enum _BtreeStatus{
    BTREE_OK    = 0,
    BTREE_ERROR = 1
} BtreeStatus;

typedef struct _BtreeNode{
    int data;
    struct _BtreeNode *left;
    struct _BtreeNode *right;
} BtreeNode;

typedef struct _Btree{
    BtreeNode *root;
} Btree;

void Btree_init( Btree *btreeHandler );
void Btree_destroy( Btree *btreeHandler );
BtreeStatus Btree_insert( Btree *btreeHandler, int data );
BtreeStatus Btree_printInorder( Btree *btreeHandler );
BtreeStatus Btree_printPreorder( Btree *btreeHandler );
BtreeStatus Btree_printPostorder( Btree *btreeHandler );

#endif