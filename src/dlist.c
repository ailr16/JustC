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
    dlist_node *temp;
	dlist_node *iterator;
	int nodeCounter = 0;

	temp = malloc(sizeof(dlist_node));
	temp->data = data;

	if(index == 0){
		temp->prev = NULL;
		temp->next = listHandler->head;

		listHandler->head->prev = temp;
		listHandler->head = temp;
	}
	else{
		iterator = listHandler->head;
		while(nodeCounter != index && iterator->next != NULL){
			iterator = iterator->next;
			nodeCounter++;
		}
		//printf("LAST %d\n", iterator->data);
		if(iterator->next == NULL){
			iterator->next = temp;
			temp->prev = iterator;
			temp->next = NULL;
			listHandler->tail = temp;
		}
		else{
			temp->prev = iterator->prev;
			temp->next = iterator;
			temp->prev->next = temp;
			temp->next->prev = temp;
		}
	}
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
int dlist_pop(dlist *listHandler){
	dlist_node *temp;
	int returnValue;

	temp = listHandler->tail;
	returnValue = listHandler->tail->data;

	listHandler->tail->prev->next = NULL;
	listHandler->tail = listHandler->tail->prev;

	free(temp);

	return returnValue;
}

/*
  Remove and return first node
*/
int dlist_popFront(dlist *listHandler){
	dlist_node *temp;
	int returnValue;

	temp = listHandler->head;
	returnValue = listHandler->head->data;

	listHandler->head->next->prev = NULL;
	listHandler->head = listHandler->head->next;

	free(temp);

	return returnValue;
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