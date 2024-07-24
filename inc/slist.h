#ifndef SLIST_H
#define SLIST_H

#include <stdlib.h>
#include <stdio.h>

#define Slist_append( list, data ) Slist_insert( &list, -1, data )
#define Slist_preppend( list, data ) Slist_insert( &list, 0, data )
#define Slist_pop( list, data ) ( Slist_getIndex( &list, -1, &data ), Slist_remove( &list, -1 ) )
#define Slist_popFront( list, data ) ( Slist_getIndex( &list, 0, &data ), Slist_remove( &list, 0 ) )

typedef enum _SlistStatus{
    SLIST_OK    = 0,
    SLIST_ERROR = 1
} SlistStatus;

typedef struct _Slist_node {
    int data;
    struct _Slist_node *next;
} SlistNode;

typedef struct _slist{
    SlistNode *head;
} Slist;

SlistStatus Slist_init( Slist *listHandler );
SlistStatus Slist_insert( Slist *listHandler, int index, int data );
SlistStatus Slist_remove( Slist *listHandler, int index );
SlistStatus Slist_getIndex( Slist *listHandler, int index, int *data );
void Slist_print( Slist *listHandler );
void Slist_free( Slist *listHandler );

#endif