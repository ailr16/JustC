#include "TEST.h"
#include "queue.h"

#define BUFFER_SIZE 6

void TEST_queue(void){
    int a[BUFFER_SIZE];
    Queue q;

    QueueStatus status;
    int retVal;

    Queue_Init( &q, BUFFER_SIZE, a );

    status = Queue_Dequeue( &q, &retVal );

    status = Queue_Enqueue( &q, 8 );
    status = Queue_Enqueue( &q, 9 );
    status = Queue_Enqueue( &q, 10 );
    status = Queue_Enqueue( &q, 11 );
    status = Queue_Enqueue( &q, 12 );
    status = Queue_Enqueue( &q, 13 );
    status = Queue_Enqueue( &q, 14 );

    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );

    status = Queue_Enqueue( &q, 14 );
    status = Queue_Enqueue( &q, 15 );
    status = Queue_Enqueue( &q, 16 );

    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
    status = Queue_Dequeue( &q, &retVal );
}
