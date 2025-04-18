#include "TEST.h"
#include "stack.h"

void TEST_stack(void){
    Stack stackH;
    StackStatus status;
    const int STACKSIZE = 6;
    int popped;

    Stack_init( &stackH, STACKSIZE );

    status = Stack_pop( &stackH, &popped );

    status = Stack_push( &stackH, 16 );
    status = Stack_push( &stackH, 17 );
    status = Stack_push( &stackH, 18 );
    status = Stack_push( &stackH, 19 );
    status = Stack_push( &stackH, 20 );
    status = Stack_push( &stackH, 21 );
    status = Stack_push( &stackH, 22 );

    status = Stack_pop( &stackH, &popped );
    status = Stack_pop( &stackH, &popped );
    status = Stack_pop( &stackH, &popped );
    status = Stack_pop( &stackH, &popped );
    status = Stack_pop( &stackH, &popped );
    status = Stack_push( &stackH, 22 );
    status = Stack_pop( &stackH, &popped );
    status = Stack_pop( &stackH, &popped );
    status = Stack_pop( &stackH, &popped );
    status = Stack_pop( &stackH, &popped );
    

    Stack_destroy( &stackH );
}

typedef struct _Squeue{
    Stack s1;
    Stack s2;
} SQueue;

void enqueue( SQueue *queueHandler, int data ){
    int pop;
    int i = 0;

    while( Stack_pop( &queueHandler->s1, &pop ) != STACK_EMPTY ){
        (void)Stack_push( &queueHandler->s2, pop );
    }

    (void)Stack_push( &queueHandler->s1, data );

    while( Stack_pop( &queueHandler->s2, &pop ) != STACK_EMPTY ){
        (void)Stack_push( &queueHandler->s1, pop );
    }
}

int dequeue( SQueue *queueHandler, int *data ){
    if( Stack_pop( &queueHandler->s1, data ) == STACK_OK )
        return 0;
    else
        return 1;
}

void TEST_queue_with_two_stack(void){
    SQueue qH;
    const int QUEUESIZE = 6;
    int dequeued;
    int status;

    Stack_init( &qH.s1, QUEUESIZE );
    Stack_init( &qH.s2, QUEUESIZE );

    enqueue( &qH, 16 );
    enqueue( &qH, 32 );
    enqueue( &qH, 64 );

    status = dequeue( &qH, &dequeued );

    enqueue( &qH, 128 );
    enqueue( &qH, 256 );
    status = dequeue( &qH, &dequeued );
    enqueue( &qH, 64 );

    status = dequeue( &qH, &dequeued );
    status = dequeue( &qH, &dequeued );
    status = dequeue( &qH, &dequeued );
    status = dequeue( &qH, &dequeued );
    status = dequeue( &qH, &dequeued );

    Stack_destroy( &qH.s1 );
    Stack_destroy( &qH.s2 );
}