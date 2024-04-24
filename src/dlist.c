#include "dlist.h"

/*
  Initialize list
*/
void dlist_init(dlist *listHandler){
    listHandler->head = NULL;
    listHandler->tail = NULL;
}

/*
  Insert node at specified index 
*/
void dlist_insert(dlist *listHandler, int index, int data){
    
}

/*
  Remove specified node index 
*/
void dlist_remove(dlist *listHandler, int index){

}

/*
  Add node at front of list
*/
void dlist_prepend(dlist *listHandler, int data){
    dlist_node *temp;

	temp = malloc(sizeof(dlist_node));
	temp->data = data;
	temp->prev = NULL;

	if(listHandler->head == NULL){
		temp->next = NULL;
		listHandler->head = temp;
		listHandler->tail = temp;
    }
	else{
		temp->next = listHandler->head;
		listHandler->head->prev = temp;
		listHandler->head = temp;
	}
}

/*
  Add node at end of list
*/
void dlist_append(dlist *listHandler, int data){
	dlist_node *temp;

	temp = malloc(sizeof(dlist_node));
	temp->data = data;
	temp->next = NULL;

	if(listHandler->head == NULL){
        temp->prev = NULL;
		listHandler->head = temp;
		listHandler->tail = temp;
    }
	else{
		temp->prev = listHandler->tail;
		listHandler->tail->next = temp;
		listHandler->tail = temp;
	}
}

/*
  Remove and return last node
*/
int  dlist_pop(dlist *listHandler){

}

/*
  Remove and return first node
*/
int  dlist_popFront(dlist *listHandler){

}

/*
  Printt all nodes in the list
*/
void dlist_print(dlist *listHandler){
	dlist_node *temp;

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
void dlist_free(dlist *listHandler){
	dlist_node * temp;

	while(listHandler->head){
		temp = listHandler->head;
		listHandler->head = listHandler->head->next;
		free(temp);
	}
}