#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef enum _queue_status{
    QUEUE_OK    = 0,
    QUEUE_FULL  = 1,
    QUEUE_EMPTY = 2,
    QUEUE_ERROR = 4
} QueueStatus;

typedef struct _queue{
    int *array;
    int head;
    int tail;
    int size;
    QueueStatus status;
} Queue;

void Queue_Init( Queue *queue, int size, int *array );
QueueStatus Queue_Enqueue( Queue *queue, int value );
QueueStatus Queue_Dequeue( Queue *queue, int *value );

#endif