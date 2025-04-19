#ifndef RBUFFER_H
#define RBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum _Rbuffer_status{
    RBUFFER_OK    = 0,
    RBUFFER_FULL  = 1,
    RBUFFER_EMPTY = 2
} RbufferStatus;

typedef struct _Rbuffer{
    void *array;
    int head;
    int tail;
    int size;
    int elementSize;
    int itemCount;
    RbufferStatus status;
} Rbuffer;

void Rbuffer_init( Rbuffer *buffer );
RbufferStatus Rbuffer_put( Rbuffer *buffer, void *value );
RbufferStatus Rbuffer_get( Rbuffer *buffer, void *value );
RbufferStatus Rbuffer_getStatus( Rbuffer *buffer );
RbufferStatus Rbuffer_flush( Rbuffer *buffer );

void Rbuffer_print( Rbuffer *buffer );

#ifdef __cplusplus
}
#endif

#endif