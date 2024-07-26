#include "btree.h"

void Btree_init( Btree *btreeHandler ){
    btreeHandler->root = NULL;
}

void Btree_destroy( Btree *btreeHandler ){
    free( btreeHandler->root );
}

BtreeStatus Btree_insert( Btree *btreeHandler, int data ){
    BtreeNode *new;

    new = malloc( sizeof( BtreeNode ) );
    if( new == NULL ) return BTREE_ERROR;

    new->data  = data;
    new->left  = NULL;
    new->right = NULL;

    if( btreeHandler->root == NULL ){
        btreeHandler->root = new;
    }
    else{
        BtreeNode *prev;
        BtreeNode *i;

        i = btreeHandler->root;
        while( i != NULL ){
            prev = i;

            if( data < prev->data ){
                i = i->left;
            }
            else{
                i = i->right;
            }
        }
        if( data < prev->data ){
            prev->left = new;
        }
        else{
            prev->right = new;
        }
    }
}


void _inorder_print( BtreeNode *node ){
    if( node != NULL ){
        _inorder_print( node->left );
        printf("%d ", node->data);
        _inorder_print( node->right );
    }
}
BtreeStatus Btree_printInorder( Btree *btreeHandler ){
    _inorder_print( btreeHandler->root );
    printf("\n");
}

void _preorder_print( BtreeNode *node ){
    if( node != NULL ){
        printf("%d ", node->data);
        _preorder_print( node->left );
        _preorder_print( node->right );
    }
}
BtreeStatus Btree_printPreorder( Btree *btreeHandler ){
    _preorder_print( btreeHandler->root );
    printf("\n");
}

void _postorder_print( BtreeNode *node ){
    if( node != NULL ){
        _postorder_print( node->left );
        _postorder_print( node->right );
        printf("%d ", node->data);
    }
}
BtreeStatus Btree_printPostorder( Btree *btreeHandler ){
    _postorder_print( btreeHandler->root );
    printf("\n");
}