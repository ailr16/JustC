#include <gtest/gtest.h>
#include "rbuffer.h"

TEST( RingBufferTests, getWhenEmpty ){
    const int BUFFER_SIZE = 6;
    static int a[BUFFER_SIZE];

    int getted = 0;

    Rbuffer bH;
    bH.array       = (void*)a;
    bH.elementSize = sizeof(int);
    bH.size        = BUFFER_SIZE;
    Rbuffer_init( &bH );

    ASSERT_EQ(RBUFFER_EMPTY, Rbuffer_get(&bH, &getted));
}

TEST( RingBufferTests, multipleGetsAndPuts ){
    const int BUFFER_SIZE = 6;
    static int a[BUFFER_SIZE];

    int getted = 0;
    int value = 0;

    Rbuffer bH;
    bH.array       = (void*)a;
    bH.elementSize = sizeof(int);
    bH.size        = BUFFER_SIZE;
    Rbuffer_init( &bH );

    for(int i = 16; i < 1025; i *= 2){
        if(i < 1024)
            ASSERT_EQ(RBUFFER_OK, Rbuffer_put(&bH, &i));
        else
            ASSERT_EQ(RBUFFER_FULL, Rbuffer_put(&bH, &i));
    }

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(16, getted);

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(32, getted);

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(64, getted);

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(128, getted);

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(256, getted);

    value = 8000;
    ASSERT_EQ(RBUFFER_OK, Rbuffer_put(&bH, &value));

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(512, getted);

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(8000, getted);

    ASSERT_EQ(RBUFFER_EMPTY, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(8000, getted);
}

TEST( RingBufferTests, customType ){
    typedef struct _CustomType{
        int integer;
        float floating;
    } CustomType;

    const int BUFFER_SIZE = 2;
    static CustomType a[BUFFER_SIZE];

    CustomType getted = { 0 };
    CustomType value = { 0 };

    Rbuffer bH;
    bH.array       = (void*)a;
    bH.elementSize = sizeof(CustomType);
    bH.size        = BUFFER_SIZE;
    Rbuffer_init( &bH );

    value.integer = 16;
    value.floating = 1.11;
    ASSERT_EQ(RBUFFER_OK, Rbuffer_put(&bH, &value));

    value.integer = 18;
    value.floating = 2.22;
    ASSERT_EQ(RBUFFER_OK, Rbuffer_put(&bH, &value));

    value.integer = 32;
    value.floating = 3.33;
    ASSERT_EQ(RBUFFER_FULL, Rbuffer_put(&bH, &value));

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(16, getted.integer);
    ASSERT_EQ(1.11f, getted.floating);

    ASSERT_EQ(RBUFFER_OK, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(18, getted.integer);
    ASSERT_EQ(2.22f, getted.floating);

    ASSERT_EQ(RBUFFER_EMPTY, Rbuffer_get(&bH, &getted));
    ASSERT_EQ(18, getted.integer);
    ASSERT_EQ(2.22f, getted.floating);
}