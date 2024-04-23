#ifndef SLIST_H
#define SLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _slist_node {
    int data;
    struct _slist_node *next;
} slist_node;

typedef struct _slist{
    slist_node *head;
    slist_node *tail;
} slist;

void slist_init(slist *listHandler);
void slist_insert(slist *listHandler, int index, int data);
void slist_remove(slist *listHandler, int index);
void slist_prepend(slist *listHandler, int data);
void slist_append(slist *listHandler, int data);
int  slist_pop(slist *listHandler);
int  slist_popFront(slist *listHandler);
void slist_print(slist *listHandler);
void slist_free(slist *listHandler);

#endif