#include "TEST.h"
#include "stack.h"

void TEST_stack(void){
    Stack stackH;
    const int STACKSIZE = 6;

    Stack_init( &stackH, STACKSIZE );

    Stack_destroy( &stackH );
}