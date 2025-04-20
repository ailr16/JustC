#ifndef SLIST_H
#define SLIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SLIST_APPEND( list, data ) Slist_insert( &list, -1, &data )
#define SLIST_PREPEND( list, data ) Slist_insert( &list, 0, &data )
#define SLIST_POP( list, data ) ( Slist_getIndex( &list, -1, &data ), Slist_remove( &list, -1 ) )
#define SLIST_POPFRONT( list, data ) ( Slist_getIndex( &list, 0, &data ), Slist_remove( &list, 0 ) )

typedef enum _SlistStatus{
    SLIST_OK    = 0,
    SLIST_ERROR = 1
} SlistStatus;

typedef struct _Slist_node {
    void* data;
    struct _Slist_node *next;
} SlistNode;

typedef struct _slist{
    SlistNode *head;
    int dataSize;
} Slist;

SlistStatus Slist_init( Slist *listHandler, int dataSize );
SlistStatus Slist_insert(Slist *listHandler, int index, void *data);
SlistStatus Slist_remove( Slist *listHandler, int index );
SlistStatus Slist_getIndex( Slist *listHandler, int index, void *data );
void Slist_free( Slist *listHandler );

#ifdef __cplusplus
}
#endif

#endif