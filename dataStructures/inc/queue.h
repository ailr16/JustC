#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum _queue_status{
    QUEUE_OK    = 0,
    QUEUE_FULL  = 1,
    QUEUE_EMPTY = 2,
    QUEUE_ERROR = 4
} QueueStatus;

typedef struct _queue{
    void* array;
    int head;
    int tail;
    int size;
    int elementSize;
    QueueStatus status;
} Queue;

void Queue_Init( Queue *queue, int size, int elementSize, void* array );
QueueStatus Queue_Enqueue( Queue *queue, void* value );
QueueStatus Queue_Dequeue( Queue *queue, void* value );
void Queue_Flush( Queue *queue );

#ifdef __cplusplus
}
#endif

#endif