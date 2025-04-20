#include <gtest/gtest.h>
#include "dlist.h"


TEST( DoubleLinkedListTests, multipleOperationsCustomType ){
    Dlist dlistH;
	int value = 1;

	Dlist_init(&dlistH, sizeof(int));

	value = 1;
	ASSERT_EQ(DLIST_OK, DLIST_APPEND(dlistH, value));

	value = 2;
	ASSERT_EQ(DLIST_OK, DLIST_APPEND(dlistH, value));

	value = 3;
	ASSERT_EQ(DLIST_OK, DLIST_APPEND(dlistH, value));

	ASSERT_EQ(DLIST_OK, DLIST_POPFRONT(dlistH, value));
    ASSERT_EQ(1, value);

	ASSERT_EQ(DLIST_OK, DLIST_POPFRONT(dlistH, value));
    ASSERT_EQ(2, value);

	ASSERT_EQ(DLIST_OK, DLIST_POPFRONT(dlistH, value));
    ASSERT_EQ(3, value);

	ASSERT_EQ(DLIST_ERROR, DLIST_POPFRONT(dlistH, value));
    ASSERT_EQ(3, value);

	Dlist_free(&dlistH);
}
