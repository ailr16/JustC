#include <gtest/gtest.h>
#include "custom_string.h"


TEST( CustomStringTests, stringLen ){
    const char testString[] = "Hello";

	EXPECT_EQ(c_strlen(testString), 5);
}
