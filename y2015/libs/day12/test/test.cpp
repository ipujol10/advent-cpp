#include <gtest/gtest.h>
#include <D12_2015/day12.hpp>

TEST(FunctionTest, SumNumbers) {
    EXPECT_EQ(d12::sumNumbers("[1,2,3]"), 6);
    EXPECT_EQ(d12::sumNumbers("{\"a\":2,\"b\":4}"), 6);
    EXPECT_EQ(d12::sumNumbers("[[[3]]]"), 3);
    EXPECT_EQ(d12::sumNumbers("{\"a\":{\"b\":4},\"c\":-1}"), 3);
    EXPECT_EQ(d12::sumNumbers("{\"a\":[-1,1]}"), 0);
    EXPECT_EQ(d12::sumNumbers("[-1,{\"a\":1}]"), 0);
    EXPECT_EQ(d12::sumNumbers("[]"), 0);
    EXPECT_EQ(d12::sumNumbers("{}"), 0);
}
