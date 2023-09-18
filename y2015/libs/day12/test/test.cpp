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

TEST(FunctionTest, SumInnerBarcket) {
    EXPECT_EQ(d12::sumNumbers("[1, 2, 3]", "red"), 6);
    EXPECT_EQ(d12::sumNumbers("{\"a\": [1, 2, 3]}", "red"), 6);
    EXPECT_EQ(d12::sumNumbers("[1,{\"c\":\"red\",\"b\":2},3]", "red"), 4);
    EXPECT_EQ(d12::sumNumbers("[1,{\"c\":\"blue\",\"b\":2},3]", "red"), 6);
    EXPECT_EQ(d12::sumNumbers(
                "{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5}", "red"), 0);
    EXPECT_EQ(d12::sumNumbers("[1,\"red\",5]", "red"), 6);
}
