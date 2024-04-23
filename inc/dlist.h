#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _dlist_node {
    int data;
    struct _dlist_node *prev;
    struct _dlist_node *next;
} dlist_node;

typedef struct _dlist{
    dlist_node *head;
    dlist_node *tail;
} dlist;

void dlist_init(dlist *listHandler);
void dlist_insert(dlist *listHandler, int index, int data);
void dlist_remove(dlist *listHandler, int index);
void dlist_prepend(dlist *listHandler, int data);
void dlist_append(dlist *listHandler, int data);
int  dlist_pop(dlist *listHandler);
int  dlist_popFront(dlist *listHandler);
void dlist_print(dlist *listHandler);
void dlist_free(dlist *listHandler);

#endif