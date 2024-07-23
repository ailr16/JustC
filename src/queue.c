#include "queue.h"

static void _Queue_checkStatus( Queue *queue );

void Queue_Init( Queue *queue, int size, int *array ){
    queue->array = array;
    queue->size = size;
    queue->head = 0;
    queue->tail = 0;
    queue->status = QUEUE_EMPTY;
}

QueueStatus Queue_Enqueue( Queue *queue, int value ){
    QueueStatus status = QUEUE_OK;
    _Queue_checkStatus( queue );

    if( queue->status != QUEUE_FULL){
        queue->array[queue->head++] = value;
        queue->status = QUEUE_OK;
    }
    else{
        status = QUEUE_ERROR;
        queue->status = QUEUE_FULL;
    }

    return status;
}

QueueStatus Queue_Dequeue( Queue *queue, int *value ){
    QueueStatus status = QUEUE_OK;

    _Queue_checkStatus( queue );

    if( queue->status != QUEUE_EMPTY ){
        *value = queue->array[queue->tail++];
        queue->status = QUEUE_OK;
    }
    else{
        status = QUEUE_ERROR;
        queue->status = QUEUE_EMPTY;
    }

    return status;
}


void _Queue_checkStatus( Queue *queue ){
    if( queue->head == queue->tail ){
        queue->status = QUEUE_EMPTY;
        queue->head = 0;
        queue->tail = 0;
    }

    else if( queue->head == queue->size ){
        queue->status = QUEUE_FULL;
    }
}