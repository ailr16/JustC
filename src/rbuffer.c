#include "rbuffer.h"

void rbuffer_checkStatus( rbuffer *buffer );

void rbuffer_init( rbuffer *buffer, int size, int *array ){
    buffer->array = array;
    buffer->head = 0;
    buffer->tail = 0;
    buffer->size = size;
    buffer->itemCount = 0;
    buffer->status = RBUFFER_EMPTY;
}

rbufferStatus rbuffer_put( rbuffer *buffer, int value ){
    rbufferStatus status = RBUFFER_OK;
    
    rbuffer_checkStatus( buffer );

    if( buffer->status != RBUFFER_FULL ){
        buffer->array[buffer->head] = value;
        buffer->head++;
        buffer->itemCount++;
        if( buffer->head == buffer->size ){
            buffer->head = 0;
        }
    }
    else{
        status = RBUFFER_FULL;
    }

    return status;
}

rbufferStatus rbuffer_get( rbuffer *buffer, int *value ){
    rbufferStatus status;

    rbuffer_checkStatus( buffer );

    if( buffer->status != RBUFFER_EMPTY ){
        *value = buffer->array[buffer->tail];
        status = RBUFFER_OK;
        buffer->tail++;
        buffer->itemCount--;
        if( buffer->tail == buffer->size ){
            buffer->tail = 0;
        }
    }
    else{
        status = RBUFFER_EMPTY;
    }

    return status;
}

rbufferStatus rbuffer_getStatus( rbuffer *buffer ){
    return buffer->status;
}

rbufferStatus rbuffer_flush( rbuffer *buffer ){
    buffer->head = 0;
    buffer->tail = 0;
    buffer->itemCount = 0;
    buffer->status = RBUFFER_EMPTY;

    return RBUFFER_OK;
}

void rbuffer_print( rbuffer *buffer ){
    printf("[ ");
    for(int i = 0; i < buffer->size; i++){
        printf("%d ", buffer->array[i]);
    }
    printf("]\n");
}

void rbuffer_checkStatus( rbuffer *buffer ){
    if( buffer->itemCount > 0 ){
        buffer->status = RBUFFER_OK;
    }

    if( buffer->itemCount == 0 ){
        buffer->status = RBUFFER_EMPTY;
    }

    if( buffer->itemCount == buffer->size ){
        buffer->status = RBUFFER_FULL;
    }
}