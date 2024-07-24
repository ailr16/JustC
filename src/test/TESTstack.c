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