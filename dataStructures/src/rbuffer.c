#include "rbuffer.h"

void Rbuffer_checkStatus( Rbuffer *buffer );

void Rbuffer_init( Rbuffer *buffer ){
    buffer->head        = 0;
    buffer->tail        = 0;
    buffer->itemCount   = 0;
    buffer->status      = RBUFFER_EMPTY;
}

RbufferStatus Rbuffer_put( Rbuffer *buffer, void *data ){
    RbufferStatus status = RBUFFER_OK;

    Rbuffer_checkStatus( buffer );

    if( buffer->status != RBUFFER_FULL ){
        memcpy( (buffer->array + (buffer->elementSize * buffer->head)), data, buffer->elementSize );
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

RbufferStatus Rbuffer_get( Rbuffer *buffer, void *value ){
    RbufferStatus status;
    
    Rbuffer_checkStatus( buffer );

    if( buffer->status != RBUFFER_EMPTY ){
        memcpy( value, (buffer->array + (buffer->elementSize * buffer->tail)), buffer->elementSize );
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

RbufferStatus Rbuffer_getStatus( Rbuffer *buffer ){
    return buffer->status;
}

RbufferStatus Rbuffer_flush( Rbuffer *buffer ){
    buffer->head = 0;
    buffer->tail = 0;
    buffer->itemCount = 0;
    buffer->status = RBUFFER_EMPTY;

    return RBUFFER_OK;
}

void Rbuffer_print( Rbuffer *buffer ){
    /*
    printf("[ ");
    for(int i = 0; i < buffer->size; i++){
        printf("%d ", buffer->array[i]);
    }
    printf("]\n");
    */
}

void Rbuffer_checkStatus( Rbuffer *buffer ){
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