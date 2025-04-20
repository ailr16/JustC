#include "dlist.h"

typedef enum _PDlistStatus{
	DLIST_EMPTY = 0,
	DLIST_1ITEM = 1
} PDlistStatus;

PDlistStatus _Dlist_checkStatus( Dlist *listHandler ){
	if( listHandler->head == NULL )    return DLIST_EMPTY;
	if(listHandler->head->next == NULL) return DLIST_1ITEM;
}

/*
  Initialize list
*/
void Dlist_init(Dlist *listHandler, int dataSize){
    listHandler->head = NULL;
	listHandler->dataSize = dataSize;
}

/*
  Insert node at specified index 
*/
DlistStatus Dlist_insert(Dlist *listHandler, int index, void* data){
    DlistNode *temp;
	DlistNode *new;

	if( index < -1 ) return DLIST_ERROR;

	if( _Dlist_checkStatus( listHandler ) == DLIST_EMPTY ){
		new = (DlistNode*)malloc( sizeof( DlistNode ) );
		if( new == NULL ) return DLIST_ERROR;

		new->data = malloc(listHandler->dataSize);
		memcpy(new->data, data, listHandler->dataSize);
		new->prev = NULL;
		new->next = NULL;

		listHandler->head = new;

		return DLIST_OK;
	}

	if( index == 0 ){
		temp = listHandler->head;

		new = (DlistNode*)malloc( sizeof( DlistNode ) );
		if( new == NULL ) return DLIST_ERROR;

		new->data = malloc(listHandler->dataSize);
		memcpy(new->data, data, listHandler->dataSize);
		new->prev = NULL;
		new->next = temp;

		temp->prev = new;

		listHandler->head = new;

		return DLIST_OK;
	}
	else if( index == -1 ){
		temp = listHandler->head;

		while(temp->next != NULL){
			temp = temp->next;
		}

		new = (DlistNode*)malloc( sizeof( DlistNode ) );
		if( new == NULL ) return DLIST_ERROR;

		temp->next = new;

		new->data = malloc(listHandler->dataSize);
		memcpy(new->data, data, listHandler->dataSize);
		new->next = NULL;
		new->prev = temp;

		return DLIST_OK;
	}
	else{
		int count = 0;

		temp = listHandler->head;

		while(temp->next != NULL){
			count++;
			if( count == index ) break;
			temp = temp->next;
		}
		if(index > count) return DLIST_ERROR;

		new = (DlistNode*)malloc( sizeof( DlistNode ) );
		if( new == NULL ) return DLIST_ERROR;

		new->data = malloc(listHandler->dataSize);
		memcpy(new->data, data, listHandler->dataSize);
		new->next = temp->next;
		new->prev = temp;

		new->next->prev = new;
		temp->next = new;
	
		return DLIST_OK;
	}
}

/*
  Remove specified node index 
*/
DlistStatus Dlist_remove(Dlist *listHandler, int index, void* data){
	DlistNode *temp;
	DlistNode *old;

	if( index < -1 ) return DLIST_ERROR;

	if( _Dlist_checkStatus( listHandler ) == DLIST_EMPTY ) return DLIST_ERROR;

	if( _Dlist_checkStatus( listHandler ) == DLIST_1ITEM ){
		old = listHandler->head;

		listHandler->head = NULL;

		free(old->data);
		free(old);

		return DLIST_OK;
	}

	if( index == 0 ){
		old = listHandler->head;
		listHandler->head = old->next;

		memcpy(data, old->data, listHandler->dataSize);

		old->next->prev = NULL;
		free(old->data);
		free(old);

		return DLIST_OK;
	}
	else if( index == -1 ){
		temp = listHandler->head;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->prev->next = NULL;

		memcpy(data, temp->data, listHandler->dataSize);

		free(temp->data);
		free(temp);
	}
	else{
		int count = 0;
		temp = listHandler->head;

		while(temp->next->next != NULL){
			count++;
			if(count == index) break;
			temp = temp->next;
		}
		if( index > count ){
			return Dlist_remove( listHandler, -1, data );
		}

		old = temp->next;

		temp->next = old->next;
		old->next->prev = old->prev;
		
		memcpy(data, old->data, listHandler->dataSize);
		free(old->data);
		free( old );

		return DLIST_OK;
	}
}

/*
  Remove all nodes and free memory
*/
void Dlist_free(Dlist *listHandler){
	DlistNode * temp;

	while(listHandler->head){
		temp = listHandler->head;
		listHandler->head = listHandler->head->next;
		free(temp->data);
		free(temp);
	}
}