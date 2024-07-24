#include "stack.h"

void Stack_init( Stack *stackHandler, int stackSize ){
    stackHandler->size = stackSize;
    stackHandler->array = (int*)malloc( stackSize*(sizeof(int)) );
    NULL;
}

void Stack_destroy( Stack *stackHandler ){
    free( stackHandler->array );
}