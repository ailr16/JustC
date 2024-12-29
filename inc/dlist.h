#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>
#include <stdio.h>

#define DLIST_APPEND( list, data ) Dlist_insert( &list, -1, data )
#define DLIST_PREPEND( list, data ) Dlist_insert( &list, 0, data )
#define DLIST_POP( list, data ) ( Dlist_remove( &list, -1, &data ) )
#define DLIST_POPFRONT( list, data ) ( Dlist_remove( &list, 0, &data ) )

typedef enum _DlistStatus{
    DLIST_OK    = 0,
    DLIST_ERROR = 1
} DlistStatus;

typedef struct _DlistNode {
    int data;
    struct _DlistNode *prev;
    struct _DlistNode *next;
} DlistNode;

typedef struct _Dlist{
    DlistNode *head;
} Dlist;

void Dlist_init( Dlist *listHandler );
DlistStatus Dlist_insert( Dlist *listHandler, int index, int data );
DlistStatus Dlist_remove( Dlist *listHandler, int index, int *data );
void Dlist_print( Dlist *listHandler );
void Dlist_free( Dlist *listHandler );

#endif