#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef enum _StackStatus{
    STACK_OK    = 0,
    STACK_EMPTY = 1,
    STACK_FULL  = 2
} StackStatus;

typedef struct _Stack{
    int size;
    int *array;
    StackStatus status;
} Stack;

void Stack_init( Stack *stackHandler, int stackSize );
void Stack_destroy( Stack *stackHandler );

#endif