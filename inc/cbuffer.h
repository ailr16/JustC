#ifndef CBUFFER_H
#define CBUFFER_H

#include <stdlib.h>
#include <stdio.h>

typedef enum _cbuffer_status{
    CBUFFER_OK,
    CBUFFER_FULL,
    CBUFFER_EMPTY
} cbufferStatus;

typedef struct _cbuffer{
    int *array;
    int head;
    int tail;
    int size;
    cbufferStatus status;
} cbuffer;

void cbuffer_init( cbuffer *buffer, int size);
cbufferStatus cbuffer_push( cbuffer *buffer, int value );
cbufferStatus cbuffer_pop( cbuffer *buffer, int *value );

void cbuffer_print( cbuffer *buffer );
#endif