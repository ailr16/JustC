#include "slist.h"

void list_init(list *listHandler){
    listHandler->head = NULL;
    listHandler->tail = NULL;
}

void list_prepend(list *listHandler, int data){
    list_node *temp;

    temp = malloc(sizeof(list_node));
    temp->data = data;

    if(listHandler->head == NULL) temp->next = NULL;
    else temp->next = listHandler->head;

    listHandler->head = temp;
}

void list_print(list *listHandler){
    list_node *i = listHandler->head;

    printf("[ ");
    while(i != NULL){
        printf(" %d ", i->data);
        i = i->next;
    }
    printf(" ]\n");
}