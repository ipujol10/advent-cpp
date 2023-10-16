#include "D24_2015/day24.hpp"
#include "utils/root.hpp"
#include <gtest/gtest.h>

TEST(FunctionTest, ReadFile) {
    const auto root = utils::getRootFolder();
    const std::string file_name(root + "libs/day24/test/files/test.txt");
    const std::vector<int> out{1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    EXPECT_EQ(d24::readFile(file_name), out);
}

TEST(FunctionTest, QuantumEntanglament) {
    EXPECT_EQ(d24::quantumEntanglament({11, 9}), 99);
    EXPECT_EQ(d24::quantumEntanglament({10, 9, 1}), 90);
    EXPECT_EQ(d24::quantumEntanglament({10, 8, 2}), 160);
}
