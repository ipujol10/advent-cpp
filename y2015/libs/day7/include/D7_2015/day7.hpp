#ifndef DAY7_HPP
#define DAY7_HPP

#include <map>
#include <string>
#include <queue>
#include <gtest/gtest.h>

namespace d7 {
    typedef unsigned short valType;
    class Circuit {
    private:
        std::map<std::string, valType> values;
        std::queue<std::string> queue;
        bool exists(const std::string& cable);
    public:
        Circuit();
        void set(valType in, const std::string& out);
        void andGate(valType a, valType b, const std::string& out);
        void leftShift(valType in, valType shift, const std::string& out);
        void notGate(valType in, const std::string& out);
        void rightShift(valType in, valType shift, const std::string& out);
        void orGate(valType a, valType b, const std::string& out);
        valType get(const std::string& cable);
        void readFromFile(const std::string& file_name);
        void override(const std::string& file_name, const std::string& el,
                valType value);
        void pass();
        valType getNumber(const std::string& in);
        FRIEND_TEST(CircuitTest, ReadFile);
        FRIEND_TEST(CircuitTest, Exists);
    };

    enum operations {
        set,
        notGate,
        orGate,
        andGate,
        leftShift,
        rightShift
    };

    operations getElements(const std::string& in, std::string* out);
}

#endif // !DAY7_HPP
