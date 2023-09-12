#include <gtest/gtest.h>
#include <D8_2015/day8.hpp>

TEST(Ex1Test, CharactersCode) {
    EXPECT_EQ(d8::charsCode("\"\""), 2);
    EXPECT_EQ(d8::charsCode("\"abc\""), 5);
    EXPECT_EQ(d8::charsCode("\"aaa\\\"aaa\""), 10);
    EXPECT_EQ(d8::charsCode("\"\\x27\""), 6);
}

TEST(Ex1Test, CharactersMemory) {
    EXPECT_EQ(d8::charsMemory("\"\""), 0);
    EXPECT_EQ(d8::charsMemory("\"abc\""), 3);
    EXPECT_EQ(d8::charsMemory("\"aaa\\\"aaa\""), 7);
    EXPECT_EQ(d8::charsMemory("\"\\x27\""), 1);
}

TEST(Ex1Test, EscpaeChars) {
    EXPECT_EQ(d8::escapeChars("\"\""), 0);
    EXPECT_EQ(d8::escapeChars("\"abc\""), 0);
    EXPECT_EQ(d8::escapeChars("\"aaa\\\"aaa\""), 1);
    EXPECT_EQ(d8::escapeChars("\"\\x27\""), 3);
}

TEST(Ex1Test, Final) {
    int count = 0;
    std::string list[] = {"\"\"", "\"abc\"", "\"aaa\\\"aaa\"", "\"\\x27\""};
    for (const auto& str : list) {
        count += d8::charsCode(str) - d8::charsMemory(str);
    }
    EXPECT_EQ(count, 12);
}

TEST(Ex2Test, NewEncode) {
    EXPECT_EQ(d8::newEncode("\"\""), 6);
    EXPECT_EQ(d8::newEncode("\"abc\""), 9);
    EXPECT_EQ(d8::newEncode("\"aaa\\\"aaa\""), 16);
    EXPECT_EQ(d8::newEncode("\"\\x27\""), 11);
}

TEST(Ex2Test, Final) {
    int count = 0;
    std::string list[] = {"\"\"", "\"abc\"", "\"aaa\\\"aaa\"", "\"\\x27\""};
    for (const auto& str : list) {
        count += d8::newEncode(str) - d8::charsCode(str);
    }
    EXPECT_EQ(count, 19);
}
