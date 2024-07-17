#ifndef RBUFFER_H
#define RBUFFER_H

#include <stdlib.h>
#include <stdio.h>

typedef enum _rbuffer_status{
    RBUFFER_OK    = 1,
    RBUFFER_FULL  = 2,
    RBUFFER_EMPTY = 4
} rbufferStatus;

typedef struct _rbuffer{
    int *array;
    int head;
    int tail;
    int size;
    int itemCount;
    rbufferStatus status;
} rbuffer;

void rbuffer_init( rbuffer *buffer, int size);
rbufferStatus rbuffer_put( rbuffer *buffer, int value );
rbufferStatus rbuffer_get( rbuffer *buffer, int *value );
rbufferStatus rbuffer_getStatus( rbuffer *buffer );
rbufferStatus rbuffer_flush( rbuffer *buffer );

void rbuffer_print( rbuffer *buffer );
#endif