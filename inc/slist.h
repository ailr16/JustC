#ifndef SLIST_H
#define SLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _Slist_node {
    int data;
    struct _Slist_node *next;
} SlistNode;

typedef struct _slist{
    SlistNode *head;
    SlistNode *tail;
} Slist;

void Slist_init( Slist *listHandler );
void Slist_insert( Slist *listHandler, int index, int data );
void Slist_remove( Slist *listHandler, int index );
void Slist_prepend( Slist *listHandler, int data );
void Slist_append( Slist *listHandler, int data );
int  Slist_pop( Slist *listHandler );
int  Slist_popFront( Slist *listHandler );
void Slist_print( Slist *listHandler );
void Slist_free( Slist *listHandler );

#endif