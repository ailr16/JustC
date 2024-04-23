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

}

/*
  Add node at end of list
*/
void dlist_append(dlist *listHandler, int data){

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

}

/*
  Remove all nodes and free memory
*/
void dlist_free(dlist *listHandler){

}