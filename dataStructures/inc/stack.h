#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum _StackStatus{
    STACK_OK    = 0,
    STACK_EMPTY = 1,
    STACK_FULL  = 2,
    STACK_ERROR = 4
} StackStatus;

typedef struct _Stack{
    int size;
    int elementSize;
    void *array;
    int pointer;
    StackStatus status;
} Stack;

StackStatus Stack_init( Stack *stackHandler, int stackSize, int elementSize );
void Stack_destroy( Stack *stackHandler );
StackStatus Stack_push( Stack *stackHandler, void* data );
StackStatus Stack_pop( Stack *stackHandler, void* data );

#ifdef __cplusplus
}
#endif

#endif