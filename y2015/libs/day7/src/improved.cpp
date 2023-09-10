#include "D7_2015/improved.hpp"
#include <cstring>
#include <regex>
#include <iostream>

namespace d7i {
    BaseGate::BaseGate(const std::string& a,
            const std::string& out): a_name(a), out(out) {
        setA();
    }

    BaseGate::BaseGate() {}

    void BaseGate::setA() {
        try {
            this->a = (valType)std::stoi(this->a_name);
            this->a_set = true;
        } catch (...) {
            this->a_set = false;
        }
    }

    bool BaseGate::getType() {
        return oneEntry;
    }

    void BaseGate::setA(valType val) {
        a_set = true;
        a = val;
    }

    std::string BaseGate::getA() {
        return a_name;
    }

    std::string BaseGate::getOut() {
        return out;
    }

    ComplexGate::ComplexGate(const std::string& a, const std::string& b,
            const std::string& out): BaseGate(a, out), b_name(b) {
        setB();
    }

    ComplexGate::ComplexGate() {}

    void ComplexGate::setB() {
        try {
            this->b = (valType)std::stoi(this->b_name);
            this->b_set = true;
        } catch (...) {
            this->b_set = false;
        }
    }

    void ComplexGate::setB(valType val) {
        b_set = true;
        b = val;
    }

    std::string ComplexGate::getB() {
        return b_name;
    }

    SetGate::SetGate(const std::string& a,
            const std::string& out): BaseGate(a, out) {
        priority = 0;
        oneEntry = true;
    }

    SetGate::SetGate() {}

    std::optional<valType> SetGate::execute() {
        priority++;
        if (a_set) {
            return a;
        }
        return {};
    }

    NotGate::NotGate(const std::string& a,
            const std::string& out): BaseGate(a, out) {
        priority = 5;
        oneEntry = true;
    }

    NotGate::NotGate() {}

    std::optional<valType> NotGate::execute() {
        priority++;
        if (a_set) {
            return ~a;
        }
        return {};
    }

    AndGate::AndGate(const std::string& a, const std::string& b,
            const std::string& out): ComplexGate(a, b, out) {
        priority = 15;
        oneEntry = false;
    }

    AndGate::AndGate() {}

    std::optional<valType> AndGate::execute() {
        priority++;
        if (a_set && b_set) {
            return a & b;
        }
        return {};
    }

    OrGate::OrGate(const std::string& a, const std::string& b,
            const std::string& out): ComplexGate(a, b, out) {
        priority = 15;
        oneEntry = false;
    }

    OrGate::OrGate() {}

    std::optional<valType> OrGate::execute() {
        priority++;
        if (a_set && b_set) {
            return a | b;
        }
        return {};
    }

    LeftShift::LeftShift(const std::string& a, const std::string& b,
            const std::string& out): ComplexGate(a, b, out) {
        priority = 10;
        oneEntry = false;
    }

    LeftShift::LeftShift() {}

    std::optional<valType> LeftShift::execute() {
        priority++;
        if (a_set && b_set) {
            return a << b;
        }
        return {};
    }

    RightShift::RightShift(const std::string& a, const std::string& b,
            const std::string& out): ComplexGate(a, b, out) {
        priority = 10;
        oneEntry = false;
    }

    RightShift::RightShift() {}

    std::optional<valType> RightShift::execute() {
        priority++;
        if (a_set && b_set) {
            return a >> b;
        }
        return {};
    }
}
