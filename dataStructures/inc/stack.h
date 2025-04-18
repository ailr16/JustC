#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef enum _StackStatus{
    STACK_OK    = 0,
    STACK_EMPTY = 1,
    STACK_FULL  = 2,
    STACK_ERROR = 4
} StackStatus;

typedef struct _Stack{
    int size;
    int *array;
    int pointer;
    StackStatus status;
} Stack;

StackStatus Stack_init( Stack *stackHandler, int stackSize );
void Stack_destroy( Stack *stackHandler );
StackStatus Stack_push( Stack *stackHandler, int data );
StackStatus Stack_pop( Stack *stackHandler, int *data );

#endif