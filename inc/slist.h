#ifndef SLIST_H
#define SLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _list_node {
    int data;
    struct _list_node *next;
} list_node;

typedef struct _list{
    list_node *head;
    list_node *tail;
} list;

void list_init(list *listHandler);
void list_insert(list *listHandler, int index, int data);
void list_remove(list *listHandler, int index);
void list_prepend(list *listHandler, int data);
void list_append(list *listHandler, int data);
int list_pop(list *listHandler);
int list_popFront(list *listHandler);
void list_print(list *listHandler);
void list_free(list *listHandler);

#endif