#include "cbuffer.h"

void cbuffer_init( cbuffer *buffer, int size ){
    buffer->head = 0;
    buffer->tail = 0;
    buffer->size = size;
    buffer->status = CBUFFER_EMPTY;
}

cbufferStatus cbuffer_push( cbuffer *buffer, int value ){
    cbufferStatus status;
    int head = buffer->head;

    if(buffer->status != CBUFFER_FULL){
        buffer->array[buffer->head] = value;
        buffer->head++;
        buffer->status = CBUFFER_OK;
        status = CBUFFER_OK;
        
        if(buffer->head >= buffer->size){
            buffer->head = 0;
        }

        if(buffer->head == buffer->tail){
            printf("%d %d\n", buffer->head, buffer->tail);
            buffer->status = CBUFFER_FULL;
            buffer->head = head;
        }
    }
    else{
        status = CBUFFER_FULL;
    }

    return status;
}

cbufferStatus cbuffer_pop( cbuffer *buffer, int *value ){
    cbufferStatus status;

    if(buffer->tail == buffer->head){
        buffer->status = CBUFFER_EMPTY;
        status = CBUFFER_EMPTY;
    }
    else{
        *value = buffer->array[buffer->tail];
        buffer->tail++;
        status = CBUFFER_OK;
    }

    return status;
}

void cbuffer_print( cbuffer *buffer ){
    printf("[ ");
    for(int i = 0; i < buffer->size; i++){
        printf("%d ", buffer->array[i]);
    }
    printf("]\n");
}