#include <gtest/gtest.h>
#include "stack.h"

TEST( StackTests, popWhenEmpty ){
    Stack stackH;
    StackStatus status;
    const int STACKSIZE = 6;
    int popped;

    Stack_init( &stackH, STACKSIZE );

    ASSERT_EQ(STACK_EMPTY, Stack_pop( &stackH, &popped ));

    Stack_destroy( &stackH );
}

TEST( StackTests, multiplePushAndPop ){
    Stack stackH;
    StackStatus status;
    const int STACKSIZE = 6;
    int popped;

    Stack_init( &stackH, STACKSIZE );

    ASSERT_EQ(STACK_OK, Stack_push( &stackH, 16 ));
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, 17 ));
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, 18 ));
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, 19 ));
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, 20 ));
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, 21 ));
    ASSERT_EQ(STACK_FULL, Stack_push( &stackH, 22 ));

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &popped ));
    ASSERT_EQ(21, popped);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &popped ));
    ASSERT_EQ(20, popped);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &popped ));
    ASSERT_EQ(19, popped);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &popped ));
    ASSERT_EQ(18, popped);

    ASSERT_EQ(STACK_OK, Stack_push( &stackH, 22 ));

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &popped ));
    ASSERT_EQ(22, popped);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &popped ));
    ASSERT_EQ(17, popped);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &popped ));
    ASSERT_EQ(16, popped);

    ASSERT_EQ(STACK_EMPTY, Stack_pop( &stackH, &popped ));
    ASSERT_EQ(16, popped);

    Stack_destroy( &stackH );
}