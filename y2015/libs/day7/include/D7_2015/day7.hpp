#ifndef DAY7_HPP
#define DAY7_HPP

#include <map>
#include <string>

namespace d7 {
    typedef unsigned short valType;
    class Circuit {
    private:
        std::map<std::string, valType> values;
    public:
        Circuit();
        void set(const std::string& out, valType value);
        void andGate(const std::string& a, const std::string& b,
                const std::string& out);
        void leftShift(const std::string& in, valType shift,
                const std::string& out);
        void notGate(const std::string& in, const std::string& out);
        void rightShift(const std::string& in, valType shift,
                const std::string& out);
        void orGate(const std::string& a, const std::string& b,
                const std::string& out);
        valType get(const std::string& cable);
    };

    enum operations {
        andGate,
        orGate,
        notGate,
        rightShift,
        leftShift,
        set
    };

    operations getElements(const std::string& in, std::string *out);
}

#endif // !DAY7_HPP
