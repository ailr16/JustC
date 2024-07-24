#include "stack.h"

void _Stack_checkStatus( Stack *stackHandler ){
    if( stackHandler->pointer <= -1 )
        stackHandler->status = STACK_EMPTY;
    else if ( stackHandler->pointer >= stackHandler->size )
        stackHandler->status = STACK_FULL;
    else
        stackHandler->status = STACK_OK;
}

StackStatus Stack_init( Stack *stackHandler, int stackSize ){
    stackHandler->size = stackSize - 1;

    stackHandler->array = (int*)malloc( stackSize*(sizeof(int)) );
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

StackStatus Stack_push( Stack *stackHandler, int data ){    
    stackHandler->pointer++;
    _Stack_checkStatus( stackHandler );

    if( stackHandler->pointer > stackHandler->size ){
        stackHandler->pointer = stackHandler->size;
        return STACK_FULL;
    }
    stackHandler->array[stackHandler->pointer] = data;

    return STACK_OK;
}

StackStatus Stack_pop( Stack *stackHandler, int *data ){
    if( stackHandler->status == STACK_EMPTY ) return STACK_EMPTY;

    *data = stackHandler->array[stackHandler->pointer];
    stackHandler->array[stackHandler->pointer] = 0;

    stackHandler->pointer--;
    _Stack_checkStatus( stackHandler );

    if( stackHandler->pointer < -1 ){
        stackHandler->pointer = -1;
    }
    return STACK_OK;
}