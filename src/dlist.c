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
void Dlist_init(Dlist *listHandler){
    listHandler->head = NULL;
}

/*
  Insert node at specified index 
*/
DlistStatus Dlist_insert(Dlist *listHandler, int index, int data){
    DlistNode *temp;
	DlistNode *new;

	if( index < -1 ) return DLIST_ERROR;

	if( _Dlist_checkStatus( listHandler ) == DLIST_EMPTY ){
		new = (DlistNode*)malloc( sizeof( DlistNode ) );
		if( new == NULL ) return DLIST_ERROR;

		new->data = data;
		new->prev = NULL;
		new->next = NULL;

		listHandler->head = new;

		return DLIST_OK;
	}

	if( index == 0 ){
		temp = listHandler->head;

		new = (DlistNode*)malloc( sizeof( DlistNode ) );
		if( new == NULL ) return DLIST_ERROR;

		new->data = data;
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

		new->data = data;
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

		new->data = data;
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
DlistStatus Dlist_remove(Dlist *listHandler, int index){
	DlistNode *temp;
	DlistNode *old;

	if( index < -1 ) return DLIST_ERROR;

	if( _Dlist_checkStatus( listHandler ) == DLIST_EMPTY ) return DLIST_ERROR;

	if( _Dlist_checkStatus( listHandler ) == DLIST_1ITEM ){
		old = listHandler->head;

		listHandler->head = NULL;

		free(old);

		return DLIST_OK;
	}

	if( index == 0 ){
		old = listHandler->head;
		listHandler->head = old->next;

		old->next->prev = NULL;
		free(old);

		return DLIST_OK;
	}
	else if( index == -1 ){
		temp = listHandler->head;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->prev->next = NULL;
		free(temp);
	}
	else{
		int count = 0;
		temp = listHandler->head;

		while(temp->next != NULL){
			count++;
			if(count == index) break;
			temp = temp->next;
		}
		if( index > count ) return DLIST_ERROR;

		old = temp->next;

		temp->next = old->next;
		old->next->prev = old->prev;

		return DLIST_OK;
	}
}

/*
  Printt all nodes in the list
*/
void Dlist_print(Dlist *listHandler){
	DlistNode *temp;

	temp = listHandler->head;

	printf("[ ");
	while(temp){
		printf("%d ", temp->data );
		temp = temp->next;
	}
	printf("]\n");
}

/*
  Remove all nodes and free memory
*/
void Dlist_free(Dlist *listHandler){
	DlistNode * temp;

	while(listHandler->head){
		temp = listHandler->head;
		listHandler->head = listHandler->head->next;
		free(temp);
	}
}