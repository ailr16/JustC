#ifndef SLIST_H
#define SLIST_H

typedef struct _list_element {
    void *data;
    struct _list_element *next;
} list_element;

#endif