#ifndef SLIST_H
#define SLIST_H

#include <stdlib.h>
#include <stdio.h>

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
void Slist_print( Slist *listHandler );
void Slist_free( Slist *listHandler );

#endif