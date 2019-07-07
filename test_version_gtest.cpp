#include "lib.h"

#include <gtest/gtest.h>

TEST(test_version_gtest, test_valid_version_gtest)
{
    ASSERT_TRUE(version() > 0);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}