#ifndef SLIST_H
#define SLIST_H

#define LIST_HEAD_INIT( name ) { &(name), &(name) }
#define LIST_HEAD( name ) \
            list_head name = LIST_HEAD_INIT( name )


typedef struct _list_head{
    struct _list_head *next;
    struct _list_head *prev;
} list_head;


typedef struct _list_element {
    int data;
    list_head list;
} list_element;


static inline void INIT_LIST_HEAD( list_head *list )
{
    list->next = list;
    list->prev = list;
}


#endif