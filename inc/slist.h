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
void list_prepend(list *listHandler, int data);
void list_print(list *listHandler);

#endif