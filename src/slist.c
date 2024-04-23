#include "slist.h"

/*
  Initialize list
*/
void slist_init(slist *listHandler){
    listHandler->head = NULL;
    listHandler->tail = NULL;
}

/*
  Add node at the specified index
*/
void slist_insert(slist *listHandler, int index, int data){
    slist_node *temp;
    slist_node *new;

    temp = listHandler->head;

    if(index == 0){
        new = malloc(sizeof(slist_node));
        new->data = data;
        new->next = temp;
        listHandler->head = new;
    }
    else{
        int i = 0;
        while(i != (index - 1) && temp->next != NULL){
            i++;
            temp = temp->next;
        }
        if(temp->next == NULL){
            new = malloc(sizeof(slist_node));
            new->data = data;
            new->next = NULL;
            temp->next = new;
            listHandler->tail = new;
        }
        else{
            new = malloc(sizeof(slist_node));
            new->data = data;
            new->next = temp->next;
            temp->next = new;
        }
    }
}

/*
  Remove the specified index node
*/
void slist_remove(slist *listHandler, int index){
    slist_node *temp;
    slist_node *deleteNode;

    temp = listHandler->head;

    if(index == 0){
        listHandler->head = listHandler->head->next;
        free(temp);
    }
    else{
        int i = 0;
        while(i != (index - 1) && temp->next->next != NULL){
            i++;
            temp = temp->next;
        }
        if(temp->next->next == NULL){
            deleteNode = temp->next;
            temp->next = NULL;
            free(deleteNode);
        }
        else{
            deleteNode = temp->next;
            temp->next = deleteNode->next;
            free(deleteNode);
        }
    }
}

/*
  Add node to front of the list
*/
void slist_prepend(slist *listHandler, int data){
    slist_node *temp;

    temp = malloc(sizeof(slist_node));
    temp->data = data;

    if(listHandler->head == NULL){
        temp->next = NULL;
        listHandler->head = temp;
        listHandler->tail = temp;
    }
    else{
        temp->next = listHandler->head;
        listHandler->head = temp;
    }
}

/*
  Add node to end of the list
*/
void slist_append(slist *listHandler, int data){
    slist_node *temp;

    temp = malloc(sizeof(slist_node));
    temp->data = data;
    temp->next = NULL;
    
    if(listHandler->head == NULL){
        listHandler->head = temp;
        listHandler->tail = temp;
    }
    else{
        listHandler->tail->next = temp;
        listHandler->tail = temp;
    }
}

/*
  Delete and return last node
*/
int slist_pop(slist *listHandler){
    slist_node *temp;
    int returnValue;

    temp = listHandler->head;
    returnValue = listHandler->tail->data;

    while(temp->next != listHandler->tail){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    listHandler->tail = temp;

    return returnValue;
}

/*
  Delete and return first node
*/
int slist_popFront(slist *listHandler){
    slist_node *temp;
    int returnValue;

    temp = listHandler->head;
    returnValue = listHandler->head->data;

    listHandler->head = listHandler->head->next;
    free(temp);

    return returnValue;
}

/*
  Print all the nodes in a list
*/
void slist_print(slist *listHandler){
    slist_node *i = listHandler->head;

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
void slist_free(slist *listHandler){
    slist_node *tmp;

    while(listHandler->head != NULL){
        tmp = listHandler->head;
        listHandler->head = listHandler->head->next;
        free(tmp);
    }
}