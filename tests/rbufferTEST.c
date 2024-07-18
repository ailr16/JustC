#include "rbuffer.h"
#include "gtest/gtest.h"

TEST(Rbuffer_Put_Test, Add_Item_Rbuffer){
    rbuffer buffer;
    EXPECT_EQ(RBUFFER_OK, rbuffer_put( &buffer, 16 ));
}