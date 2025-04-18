#include <gtest/gtest.h>
#include "stack.h"


TEST( StackTests, popWhenEmpty ){
    const int STACK_SIZE = 6;
    const int ELEMENT_SIZE = sizeof(double);
    Stack stackH;
    double poppedVal = 0;
    double newVal = 0;

    Stack_init(&stackH, STACK_SIZE, ELEMENT_SIZE);

    ASSERT_EQ(STACK_EMPTY, Stack_pop( &stackH, &poppedVal ));

    Stack_destroy( &stackH );
}


TEST( StackTests, multiplePushAndPop ){
    const int STACK_SIZE = 6;
    const int ELEMENT_SIZE = sizeof(double);
    Stack stackH;
    double poppedVal = 0;
    double newVal = 0;

    Stack_init(&stackH, STACK_SIZE, ELEMENT_SIZE);

    newVal = 16;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    newVal = 17;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    newVal = 18;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    newVal = 19;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    newVal = 20;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    newVal = 21;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    newVal = 22;
    ASSERT_EQ(STACK_FULL, Stack_push( &stackH, &newVal ));

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &poppedVal ));
    ASSERT_EQ(21.0f, poppedVal);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &poppedVal ));
    ASSERT_EQ(20.0f, poppedVal);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &poppedVal ));
    ASSERT_EQ(19.0f, poppedVal);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &poppedVal ));
    ASSERT_EQ(18.0f, poppedVal);

    newVal = 22;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &poppedVal ));
    ASSERT_EQ(22.0f, poppedVal);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &poppedVal ));
    ASSERT_EQ(17.0f, poppedVal);

    ASSERT_EQ(STACK_OK, Stack_pop( &stackH, &poppedVal ));
    ASSERT_EQ(16.0f, poppedVal);

    ASSERT_EQ(STACK_EMPTY, Stack_pop( &stackH, &poppedVal ));
    ASSERT_EQ(16.0f, poppedVal);

    Stack_destroy( &stackH );
}


TEST( StackTests, customType ){
    typedef struct _CustomType
    {
        int integer;
        float floating;
    } CustomType;
    
    const int STACK_SIZE = 3;
    const int ELEMENT_SIZE = sizeof(CustomType);
    Stack stackH;
    CustomType poppedVal;
    CustomType newVal;

    Stack_init(&stackH, STACK_SIZE, ELEMENT_SIZE);

    newVal.integer = 16;
    newVal.floating = 1.23;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    newVal.integer = 17;
    newVal.floating = 2.34;
    ASSERT_EQ(STACK_OK, Stack_push( &stackH, &newVal ));

    ASSERT_EQ(STACK_OK, Stack_pop(&stackH, &poppedVal));
    ASSERT_EQ(17, poppedVal.integer);
    ASSERT_EQ(2.34f, poppedVal.floating);

    ASSERT_EQ(STACK_OK, Stack_pop(&stackH, &poppedVal));
    ASSERT_EQ(16, poppedVal.integer);
    ASSERT_EQ(1.23f, poppedVal.floating);

    Stack_destroy( &stackH );
}