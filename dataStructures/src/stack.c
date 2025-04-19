#include "stack.h"

StackStatus _Stack_checkStatus( Stack *stackHandler ){
    if( stackHandler->pointer <= -1 )
        stackHandler->status = STACK_EMPTY;
    else if ( stackHandler->pointer >= stackHandler->size )
        stackHandler->status = STACK_FULL;
    else
        stackHandler->status = STACK_OK;

    return stackHandler->status;
}

StackStatus Stack_init( Stack *stackHandler, int stackSize, int elementSize ){
    stackHandler->size = stackSize - 1;
    stackHandler->elementSize = elementSize;

    stackHandler->array = (void*)malloc( stackSize*elementSize );
    if( stackHandler->array == NULL ){
        stackHandler->status = STACK_ERROR;
        return STACK_ERROR;
    }

    stackHandler->pointer = -1;
    stackHandler->status = STACK_EMPTY;
}

void Stack_destroy( Stack *stackHandler ){
    free( stackHandler->array );
    stackHandler->pointer = -1;
    stackHandler->size = 0;
    stackHandler->status = STACK_EMPTY;
}

StackStatus Stack_push( Stack *stackHandler, void* data ){
    if( _Stack_checkStatus( stackHandler ) == STACK_FULL )
        return STACK_FULL;
    
    stackHandler->pointer++;
    memcpy(stackHandler->array + (stackHandler->pointer * stackHandler->elementSize),
           data,
           stackHandler->elementSize);

    _Stack_checkStatus( stackHandler );

    return STACK_OK;
}

StackStatus Stack_pop( Stack *stackHandler, void* data ){
    if( _Stack_checkStatus( stackHandler ) == STACK_EMPTY ) return STACK_EMPTY;

    memcpy(data,
           stackHandler->array + (stackHandler->pointer * stackHandler->elementSize),
           stackHandler->elementSize);
    stackHandler->pointer--;

    _Stack_checkStatus( stackHandler );
    
    return STACK_OK;
}