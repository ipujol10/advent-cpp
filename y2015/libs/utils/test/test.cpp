#include "utils/root.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, GetRootFolder) {
    EXPECT_EQ(utils::getRootFolder(), "../../../../../");
}
