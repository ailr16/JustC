#ifndef DLIST_H
#define DLIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DLIST_APPEND( list, data ) Dlist_insert( &list, -1, &data )
#define DLIST_PREPEND( list, data ) Dlist_insert( &list, 0, &data )
#define DLIST_POP( list, data ) ( Dlist_remove( &list, -1, &data ) )
#define DLIST_POPFRONT( list, data ) ( Dlist_remove( &list, 0, &data ) )

typedef enum _DlistStatus{
    DLIST_OK    = 0,
    DLIST_ERROR = 1
} DlistStatus;

typedef struct _DlistNode {
    void* data;
    struct _DlistNode *prev;
    struct _DlistNode *next;
} DlistNode;

typedef struct _Dlist{
    DlistNode *head;
    int dataSize;
} Dlist;

void Dlist_init( Dlist *listHandler, int dataSize );
DlistStatus Dlist_insert( Dlist *listHandler, int index, void* data );
DlistStatus Dlist_remove( Dlist *listHandler, int index, void* data );
void Dlist_free( Dlist *listHandler );

#ifdef __cplusplus
}
#endif

#endif