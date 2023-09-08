#ifndef DAY7_HPP
#define DAY7_HPP

#include <map>
#include <string>

namespace d7 {
    typedef unsigned short valType;
    class Circuit {
    private:
        std::map<std::string, valType> values;
        valType getNumericalValue(const std::string& in);
    public:
        Circuit();
        void set(const std::string& out, const std::string& value);
        void andGate(const std::string& a, const std::string& b,
                const std::string& out);
        void leftShift(const std::string& in, const std::string& shift,
                const std::string& out);
        void notGate(const std::string& in, const std::string& out);
        void rightShift(const std::string& in, const std::string& shift,
                const std::string& out);
        void orGate(const std::string& a, const std::string& b,
                const std::string& out);
        valType get(const std::string& cable);
        void print();
        void pass(const std::string& file_name);
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
