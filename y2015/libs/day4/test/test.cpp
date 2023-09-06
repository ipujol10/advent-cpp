#include <gtest/gtest.h>
#include <D4_2015/day4.hpp>

TEST(MD5Test, Good) {
    EXPECT_EQ(
            d4::md5("The quick brown fox jumps over the lazy dog"),
            "9e107d9d372bb6826bd81d3542a419d6"
            );
    EXPECT_EQ(
            d4::md5("The quick brown fox jumps over the lazy dog."),
            "e4d909c290d0fb1ca068ffaddf22cbd0"
            );
    EXPECT_EQ(d4::md5(""), "d41d8cd98f00b204e9800998ecf8427e");
}

TEST(GoodHashTest, Good) {
    EXPECT_TRUE(d4::goodHash("000001dbbfa"));
    EXPECT_TRUE(d4::goodHash("000006136ef"));
    EXPECT_FALSE(d4::goodHash("000016136ef"));
}

TEST(GetNumberTest, Good) {
    EXPECT_EQ(d4::getNumber("abcdef"), "609043");
    EXPECT_EQ(d4::getNumber("pqrstuv"), "1048970");
}
