#include "rbuffer.h"

void rbuffer_init( rbuffer *buffer, int size ){
    buffer->head = 0;
    buffer->tail = 0;
    buffer->size = size;
    buffer->status = RBUFFER_EMPTY;
}

rbufferStatus rbuffer_push( rbuffer *buffer, int value ){
    rbufferStatus status;
    int head = buffer->head;

    if(buffer->status != RBUFFER_FULL){
        buffer->array[buffer->head] = value;
        buffer->head++;
        buffer->status = RBUFFER_OK;
        status = RBUFFER_OK;
        
        if(buffer->head >= buffer->size){
            buffer->head = 0;
        }

        if(buffer->head == buffer->tail){
            printf("%d %d\n", buffer->head, buffer->tail);
            buffer->status = RBUFFER_FULL;
            buffer->head = head;
        }
    }
    else{
        status = RBUFFER_FULL;
    }

    return status;
}

rbufferStatus rbuffer_pop( rbuffer *buffer, int *value ){
    rbufferStatus status;

    if(buffer->tail == buffer->head){
        buffer->status = RBUFFER_EMPTY;
        status = RBUFFER_EMPTY;
    }
    else{
        *value = buffer->array[buffer->tail];
        buffer->tail++;
        status = RBUFFER_OK;
    }

    return status;
}

void cbuffer_print( rbuffer *buffer ){
    printf("[ ");
    for(int i = 0; i < buffer->size; i++){
        printf("%d ", buffer->array[i]);
    }
    printf("]\n");
}