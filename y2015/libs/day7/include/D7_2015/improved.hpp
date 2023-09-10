#ifndef IMPROVED_HPP
#define IMPROVED_HPP

#include <optional>
#include <string>
#include <gtest/gtest.h>

namespace d7i {
    typedef unsigned short valType;

    class BaseGate {
    protected:
        const std::string a_name;
        bool set_a;
        valType a;
        const std::string out;
    public:
        BaseGate(const std::string& a, const std::string out);
        virtual std::optional<valType> execute();
    };

    class SetGate: public BaseGate {
    public:
        std::optional<valType> execute();
    };

    class NotGate: public BaseGate {
    public:
        std::optional<valType> execute();
    };

    class ComplexGate: public BaseGate {
    protected:
        const std::string b_name;
        bool set_b;
        valType b;
    public:
        ComplexGate(const std::string& a, const std::string& b,
                const std::string& out);
    };

    class AndGate: public ComplexGate {
    public:
        std::optional<valType> execute();
    };

    class OrGate: public ComplexGate {
    public:
        std::optional<valType> execute();
    };

    class LeftShift: public ComplexGate {
    public:
        std::optional<valType> execute();
    };

    class RightShif: public ComplexGate {
    public:
        std::optional<valType> execute();
    };
}

#endif // !IMPROVED_HPP
