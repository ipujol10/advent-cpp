#include <gtest/gtest.h>
#include <D11_2015/day11.hpp>

TEST(FunctionTest, IncreaseLetter) {
    char letter = 'a';
    EXPECT_FALSE(d11::increaseLetter(letter));
    EXPECT_EQ(letter, 'b');
    EXPECT_FALSE(d11::increaseLetter(letter));
    EXPECT_EQ(letter, 'c');
    letter = 'z';
    EXPECT_TRUE(d11::increaseLetter(letter));
    EXPECT_EQ(letter, 'a');
}

TEST(FunctionTest, NextWord) {
    std::string word = "xx";
    d11::nextWord(word);
    EXPECT_EQ(word, "xy");
    d11::nextWord(word);
    EXPECT_EQ(word, "xz");
    d11::nextWord(word);
    EXPECT_EQ(word, "ya");
    d11::nextWord(word);
    EXPECT_EQ(word, "yb");
    word = "zz";
    d11::nextWord(word);
    EXPECT_EQ(word, "aa");
}

TEST(ConditionsTest, Incresing) {
    EXPECT_TRUE(d11::incresing("abc"));
    EXPECT_TRUE(d11::incresing("bcd"));
    EXPECT_TRUE(d11::incresing("cde"));
    EXPECT_TRUE(d11::incresing("xyz"));
    EXPECT_FALSE(d11::incresing("abd"));
    EXPECT_TRUE(d11::incresing("hijklmmn"));
    EXPECT_FALSE(d11::incresing("abbceffg"));
}

TEST(ConditionsTest, NotConfusing) {
    EXPECT_FALSE(d11::notConfusing("hijklmmn"));
    EXPECT_TRUE(d11::notConfusing("abbceffg"));
    EXPECT_TRUE(d11::notConfusing("abbcegjk"));
    EXPECT_FALSE(d11::notConfusing("ghijklmn"));
}

TEST(ConditionsTest, TwoPairs) {
    EXPECT_FALSE(d11::twoPairs("hijklmmn"));
    EXPECT_TRUE(d11::twoPairs("abbceffg"));
    EXPECT_FALSE(d11::twoPairs("abbcegjk"));
    EXPECT_FALSE(d11::twoPairs("abcdefgh"));
    EXPECT_TRUE(d11::twoPairs("abcdffaa"));
    EXPECT_FALSE(d11::twoPairs("ghijklmn"));
    EXPECT_TRUE(d11::twoPairs("ghjaabcc"));
}

TEST(FunctionTest, NextPassword) {
    std::string password = "abcdefgh";
    d11::nextPassword(password);
    EXPECT_EQ(password, "abcdffaa");
    
    password = "ghijklmn";
    d11::nextPassword(password);
    EXPECT_EQ(password, "ghjaabcc");
}
