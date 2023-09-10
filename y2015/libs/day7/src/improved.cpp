#include "D7_2015/improved.hpp"
#include <cstring>
#include <regex>
#include <iostream>

namespace d7i {
    BaseGate::BaseGate(const std::string& a,
            const std::string& out): a_name(a), out(out) {
        setA();
    }

    void BaseGate::setA() {
        try {
            this->a = (valType)std::stoi(this->a_name);
            this->a_set = true;
        } catch (...) {
            this->a_set = false;
        }
    }

    ComplexGate::ComplexGate(const std::string& a, const std::string& b,
            const std::string& out): BaseGate(a, out), b_name(b) {
        setB();
    }

    void ComplexGate::setB() {
        try {
            this->b = (valType)std::stoi(this->b_name);
            this->b_set = true;
        } catch (...) {
            this->b_set = false;
        }
    }

    SetGate::SetGate(const std::string& a,
            const std::string& out): BaseGate(a, out) {
        priority = 0;
    }
}
