#include "D7_2015/day7.hpp"
#include <iostream>
#include <regex>

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

    operations getElements(const std::string &in, std::string *out) {
        std::regex rgx("^(.+) -> (.+)$");
        std::regex set("^([0-9]+)$");
        std::regex andR("^([a-z]+) AND ([a-z]+)$");
        std::regex orR("^([a-z]+) OR ([a-z]+)$");
        std::regex lshift("^([a-z]+) LSHIFT ([a-z]+)$");
        std::regex rshift("^([a-z]+) RSHIFT ([a-z]+)$");
        std::regex notR("^NOT ([a-z]+)$");
        std::smatch matches;
        std::string output;

        std::regex_match(in, matches, rgx);
        output = matches[2];

        std::smatch input;
        std::string first_match = matches[1];
        if (std::regex_match(first_match, input, set)) {
            out[0] = input[1];
            out[1] = output;
            return operations::set;
        }
    }
}
