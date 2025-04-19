#include <gtest/gtest.h>
#include "queue.h"

TEST( QueueTests, multipleEnqueuesAndDequeues ){
    const int QUEUE_SIZE = 4;
    int array[QUEUE_SIZE];
    Queue qH;

    float value = 0;

    Queue_Init(&qH, QUEUE_SIZE, sizeof(float), array);

    value = 6;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value = 7;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value = 8;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value = 9;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value = 10;
    ASSERT_EQ(QUEUE_FULL, Queue_Enqueue(&qH, &value));

    ASSERT_EQ(QUEUE_OK, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(6.0f, value);

    ASSERT_EQ(QUEUE_OK, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(7.0f, value);

    ASSERT_EQ(QUEUE_OK, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(8.0f, value);

    ASSERT_EQ(QUEUE_OK, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(9.0f, value);

    ASSERT_EQ(QUEUE_EMPTY, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(9.0f, value);

    value = 10;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value = 10;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    Queue_Flush(&qH);

    ASSERT_EQ(QUEUE_EMPTY, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(10.0f, value);
}

TEST( QueueTests, customType ){
    typedef struct
    {
        int integer;
        float floating;
    } CustomType;
    
    const int QUEUE_SIZE = 4;
    CustomType array[QUEUE_SIZE];
    CustomType value = { 0 };
    
    Queue qH;
    Queue_Init(&qH, QUEUE_SIZE, sizeof(CustomType), array);

    value.integer = 6;
    value.floating = 1.1;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value.integer = 7;
    value.floating = 1.2;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value.integer = 8;
    value.floating = 1.3;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value.integer = 9;
    value.floating = 1.4;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value.integer = 10;
    value.floating = 1.5;
    ASSERT_EQ(QUEUE_FULL, Queue_Enqueue(&qH, &value));

    ASSERT_EQ(QUEUE_OK, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(6, value.integer);
    ASSERT_EQ(1.1f, value.floating);

    ASSERT_EQ(QUEUE_OK, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(7, value.integer);
    ASSERT_EQ(1.2f, value.floating);

    ASSERT_EQ(QUEUE_OK, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(8, value.integer);
    ASSERT_EQ(1.3f, value.floating);

    ASSERT_EQ(QUEUE_OK, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(9, value.integer);
    ASSERT_EQ(1.4f, value.floating);

    ASSERT_EQ(QUEUE_EMPTY, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(9, value.integer);
    ASSERT_EQ(1.4f, value.floating);

    value.integer = 10;
    value.floating = 1.5;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    value.integer = 10;
    value.floating = 1.5;
    ASSERT_EQ(QUEUE_OK, Queue_Enqueue(&qH, &value));

    Queue_Flush(&qH);

    ASSERT_EQ(QUEUE_EMPTY, Queue_Dequeue(&qH, &value));
    ASSERT_EQ(10, value.integer);
    ASSERT_EQ(1.5f, value.floating);
}