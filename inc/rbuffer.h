#ifndef RBUFFER_H
#define RBUFFER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum _rbuffer_status{
    RBUFFER_OK    = 0,
    RBUFFER_FULL  = 1,
    RBUFFER_EMPTY = 2
} rbufferStatus;

typedef struct _rbuffer{
    void *array;
    int head;
    int tail;
    int size;
    int elementSize;
    int itemCount;
    rbufferStatus status;
} rbuffer;

void rbuffer_init( rbuffer *buffer );
rbufferStatus rbuffer_put( rbuffer *buffer, void *value );
rbufferStatus rbuffer_get( rbuffer *buffer, void *value );
rbufferStatus rbuffer_getStatus( rbuffer *buffer );
rbufferStatus rbuffer_flush( rbuffer *buffer );

void rbuffer_print( rbuffer *buffer );
#endif