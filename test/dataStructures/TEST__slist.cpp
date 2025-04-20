#include <gtest/gtest.h>
#include "slist.h"


TEST( SingleLinkedListTests, multipleOperationsCustomType ){
    typedef struct{
        int integer;
        float floating;
    } CustomType;

    Slist slistH;
    CustomType value;

    Slist_init(&slistH, sizeof(CustomType));

    value.integer = 10;
    value.floating = 10.1;
    ASSERT_EQ(SLIST_OK, SLIST_APPEND(slistH, value));

    value.integer = 12;
    value.floating = 12.1;
    ASSERT_EQ(SLIST_OK, SLIST_APPEND(slistH, value));

    value.integer = 13;
    value.floating = 13.1;
    ASSERT_EQ(SLIST_OK, SLIST_APPEND(slistH, value));

    ASSERT_EQ(SLIST_OK, SLIST_POPFRONT(slistH, value));
    ASSERT_EQ(10, value.integer);
    ASSERT_EQ(10.1f, value.floating);

    ASSERT_EQ(SLIST_OK, SLIST_POPFRONT(slistH, value));
    ASSERT_EQ(12, value.integer);
    ASSERT_EQ(12.1f, value.floating);

    ASSERT_EQ(SLIST_OK, SLIST_POPFRONT(slistH, value));
    ASSERT_EQ(13, value.integer);
    ASSERT_EQ(13.1f, value.floating);

    ASSERT_EQ(SLIST_ERROR, SLIST_POPFRONT(slistH, value));
    ASSERT_EQ(13, value.integer);
    ASSERT_EQ(13.1f, value.floating);

    Slist_free(&slistH);
}
