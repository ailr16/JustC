#include "slist.h"

/*
  Initialize list
*/
SlistStatus Slist_init(Slist *listHandler){
    listHandler->head = NULL;

    return SLIST_OK;
}

/*
  Add node at the specified index
*/
SlistStatus Slist_insert(Slist *listHandler, int index, int data){
    SlistNode *temp;
    SlistNode *new;
    
    if( index == 0 ){
        // Insert at the beggining
        temp = listHandler->head;

        new = (SlistNode*)malloc( sizeof(SlistNode) );
        if( new == NULL ) return SLIST_ERROR;

        new->data = data;
        new->next = temp;

        listHandler->head = new;

        return SLIST_OK;
    }
    else if( index == -1 ){
        // Insert at the end
        temp = listHandler->head;

        while( temp->next != NULL ){
            temp = temp->next;
        }

        new = (SlistNode*)malloc( sizeof(SlistNode) );
        if( new == NULL ) return SLIST_ERROR;

        new->data = data;
        new->next = NULL;

        temp->next = new;

        return SLIST_OK;
    }
    else{
        // Any other index
        temp = listHandler->head;
        int count = 0;

        if( index < -1 ){
            return SLIST_ERROR;
        }

        while( temp->next != NULL ){
            count++;
            if( count >= index ) break;
            temp = temp->next;
        }

        new = (SlistNode*)malloc( sizeof(SlistNode) );
        if( new == NULL ) return SLIST_ERROR;

        new->data = data;
        new->next = temp->next;

        temp->next = new;
        return SLIST_OK;
    }
}

/*
  Remove the specified index node
*/
void Slist_remove(Slist *listHandler, int index){
    
}

/*
  Print all the nodes in a list
*/
void Slist_print(Slist *listHandler){
    SlistNode *i = listHandler->head;

    printf("[ ");
    while(i != NULL){
        printf(" %d ", i->data);
        i = i->next;
    }
    printf(" ]\n");
}

/*
  Delete all nodes and free memory
*/
void Slist_free(Slist *listHandler){
    SlistNode *tmp;

    while(listHandler->head != NULL){
        tmp = listHandler->head;
        listHandler->head = listHandler->head->next;
        free(tmp);
    }
}