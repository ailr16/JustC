#include "slist.h"

typedef enum _PrivateSlistStatus{
    SLIST_EMPTY = 0,
    SLIST_1ITEM = 1
} PSlistStatus;


PSlistStatus _Slist_checkStatus( Slist *listHandler );

/*
  Initialize list
*/
SlistStatus Slist_init(Slist *listHandler, int dataSize){
    listHandler->head = NULL;
    listHandler->dataSize = dataSize;

    return SLIST_OK;
}

/*
  Add node at the specified index
*/
SlistStatus Slist_insert(Slist *listHandler, int index, void *data){
    SlistNode *temp;
    SlistNode *new;
    
    if( index < -1 ) return SLIST_ERROR;

    if( (_Slist_checkStatus( listHandler ) == SLIST_EMPTY) ){
        new = (SlistNode*)malloc( sizeof(SlistNode) );
        if( new == NULL )
            return SLIST_ERROR;

        new->data = malloc(listHandler->dataSize);
        memcpy(new->data, data, listHandler->dataSize);
        new->next = NULL;

        listHandler->head = new;

        return SLIST_OK;
    }

    if( index == 0 ){
        // Insert at the beggining
        temp = listHandler->head;

        new = (SlistNode*)malloc( sizeof(SlistNode) );
        if( new == NULL ) return SLIST_ERROR;

        new->data = malloc(listHandler->dataSize);
        memcpy(new->data, data, listHandler->dataSize);
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

        new->data = malloc(listHandler->dataSize);
        memcpy(new->data, data, listHandler->dataSize);
        new->next = NULL;

        temp->next = new;

        return SLIST_OK;
    }
    else{
        // Any other index
        temp = listHandler->head;
        int count = 0;

        while( temp->next != NULL ){
            count++;
            if( count >= index ) break;
            temp = temp->next;
        }

        new = (SlistNode*)malloc( sizeof(SlistNode) );
        if( new == NULL ) return SLIST_ERROR;

        new->data = malloc(listHandler->dataSize);
        memcpy(new->data, data, listHandler->dataSize);
        new->next = temp->next;

        temp->next = new;
        return SLIST_OK;
    }
}

/*
  Remove the specified index node
*/
SlistStatus Slist_remove(Slist *listHandler, int index){
    SlistNode *temp;
    SlistNode *old;

    if( _Slist_checkStatus( listHandler ) == SLIST_EMPTY ) return SLIST_ERROR;

    if( _Slist_checkStatus( listHandler ) == SLIST_1ITEM ){
        // One item remaining
        temp = listHandler->head;
        listHandler->head = NULL;

        free( temp->data );
        free( temp );
        return SLIST_OK;
    }

    if( index == 0 ){
        // Remove item at the beggining
        temp = listHandler->head;
        listHandler->head = temp->next;

        free( temp->data );
        free(temp);

        return SLIST_OK;
    }
    else if( index == -1 ){
        // Remove item at the end
        temp = listHandler->head;

        while( temp->next->next != NULL ){
            temp = temp->next;
        }
        old = temp->next;
        temp->next = NULL;

        free(old->data);
        free(old);

        return SLIST_OK;
    }
    else{
        // Remove item at any index
        int count = 0;

        temp = listHandler->head;

        while( temp->next->next != NULL ){
            count++;
            if( count >= index ) break;
            temp = temp->next;
        }
        old = temp->next;
        temp->next = old->next;

        free(old->data);
        free(old);

        return SLIST_OK;
    }
}

/*
  Remove the specified index node
*/
SlistStatus Slist_getIndex( Slist *listHandler, int index, void *data ){
    SlistNode *temp;

    if( _Slist_checkStatus( listHandler ) == SLIST_EMPTY ) return SLIST_ERROR;
    if( index < -1 ) return SLIST_ERROR;

    if( _Slist_checkStatus( listHandler ) == SLIST_1ITEM ){
        memcpy(data, listHandler->head->data, listHandler->dataSize);
        return SLIST_OK;
    }

    if( index == 0 ){
        memcpy(data, listHandler->head->data, listHandler->dataSize);
        return SLIST_OK;
    }
    else if( index == -1 ){
        temp = listHandler->head;
        while( temp->next != NULL ){
            temp = temp->next;
        }
        memcpy(data, temp->data, listHandler->dataSize);

        return SLIST_OK;
    }
    else{
        int count = 0;

        temp = listHandler->head;
        while( temp->next != NULL ){
            count++;
            if( count >= index + 1 ) break;
            temp = temp->next;
        }
        memcpy(data, temp->data, listHandler->dataSize);

        return SLIST_OK;
    }
}

/*
  Delete all nodes and free memory
*/
void Slist_free(Slist *listHandler){
    SlistNode *tmp;

    while(listHandler->head != NULL){
        tmp = listHandler->head;
        listHandler->head = listHandler->head->next;
        free(tmp->data);
        free(tmp);
    }
}

PSlistStatus _Slist_checkStatus( Slist *listHandler ){
    if( listHandler->head == NULL ){
        return SLIST_EMPTY;
    }
    if( listHandler->head->next == NULL ){
        return SLIST_1ITEM;
    }
}
