#ifndef RBUFFER_H
#define RBUFFER_H

#include <stdlib.h>
#include <stdio.h>

typedef enum _rbuffer_status{
    RBUFFER_OK,
    RBUFFER_FULL,
    RBUFFER_EMPTY
} rbufferStatus;

typedef struct _rbuffer{
    int *array;
    int head;
    int tail;
    int size;
    rbufferStatus status;
} rbuffer;

void rbuffer_init( rbuffer *buffer, int size);
rbufferStatus rbuffer_push( rbuffer *buffer, int value );
rbufferStatus rbuffer_pop( rbuffer *buffer, int *value );

void rbuffer_print( rbuffer *buffer );
#endif