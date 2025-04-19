#include "queue.h"

static void _Queue_checkStatus( Queue *queue );

void Queue_Init( Queue *queue, int size, int elementSize, void* array ){
    queue->array = array;
    queue->size = size;
    queue->head = 0;
    queue->tail = 0;
    queue->status = QUEUE_EMPTY;
    queue->elementSize = elementSize;
}

QueueStatus Queue_Enqueue( Queue *queue, void* value ){
    QueueStatus status = QUEUE_OK;
    _Queue_checkStatus( queue );

    if( queue->status != QUEUE_FULL){
        memcpy(queue->array + (queue->elementSize * queue->head++),
               value,
               queue->elementSize);
        queue->status = QUEUE_OK;
    }
    else{
        status = QUEUE_FULL;
        queue->status = QUEUE_FULL;
    }

    return status;
}

QueueStatus Queue_Dequeue( Queue *queue, void* value ){
    QueueStatus status = QUEUE_OK;

    _Queue_checkStatus( queue );

    if( queue->status != QUEUE_EMPTY ){
        memcpy(value,
               queue->array + (queue->elementSize * queue->tail++),
               queue->elementSize);
        queue->status = QUEUE_OK;
    }
    else{
        status = QUEUE_EMPTY;
        queue->status = QUEUE_EMPTY;
    }

    return status;
}

void Queue_Flush( Queue *queue ){
    queue->head = 0;
    queue->tail = 0;
    queue->status = QUEUE_EMPTY;

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