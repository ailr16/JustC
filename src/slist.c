#include "slist.h"

/*
  Initialize list
*/
void list_init(list *listHandler){
    listHandler->head = NULL;
    listHandler->tail = NULL;
}

/*
  Add node at the specified index
*/
void list_insert(list *listHandler, int index, int data){
    list_node *temp;
    list_node *new;

    temp = listHandler->head;

    if(index == 0){
        new = malloc(sizeof(list_node));
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
            new = malloc(sizeof(list_node));
            new->data = data;
            new->next = NULL;
            temp->next = new;
            listHandler->tail = new;
        }
        else{
            new = malloc(sizeof(list_node));
            new->data = data;
            new->next = temp->next;
            temp->next = new;
        }
    }
}

/*
  Remove the specified index node
*/
void list_remove(list *listHandler, int index){
    list_node *temp;
    list_node *deleteNode;

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
void list_prepend(list *listHandler, int data){
    list_node *temp;

    temp = malloc(sizeof(list_node));
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
void list_append(list *listHandler, int data){
    list_node *temp;

    temp = malloc(sizeof(list_node));
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
int list_pop(list *listHandler){
    list_node *temp;
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
int list_popFront(list *listHandler){
    list_node *temp;
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
void list_print(list *listHandler){
    list_node *i = listHandler->head;

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
void list_free(list *listHandler){
    list_node *tmp;

    while(listHandler->head != NULL){
        tmp = listHandler->head;
        listHandler->head = listHandler->head->next;
        free(tmp);
    }
}