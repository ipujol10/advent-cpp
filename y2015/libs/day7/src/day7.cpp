#include "D7_2015/day7.hpp"

namespace d7 {
    Circuit::Circuit() {
        values["a"] = 0;
    }

    void Circuit::set(const std::string& out, valType value) {
        values[out] = value;
    }

    valType Circuit::get(const std::string& cable) {
        return values[cable];
    }

    void Circuit::andGate(const std::string& a, const std::string& b,
                const std::string& out) {
        values[out] = values[a] & values[b];
    }

    void Circuit::orGate(const std::string& a, const std::string& b,
            const std::string& out) {
        values[out] = values[a] | values[b];
    }

    void Circuit::notGate(const std::string& in, const std::string& out) {
        values[out] = ~values[in];
    }

    void Circuit::leftShift(const std::string& in, valType shift,
                const std::string& out) {
        values[out] = values[in] << shift;
    }

    void Circuit::rightShift(const std::string& in, valType shift,
                const std::string& out) {
        values[out] = values[in] >> shift;
    }
}
