#include "D7_2015/day7.hpp"
#include <iostream>
#include <regex>

namespace d7 {
    Circuit::Circuit() {
        values["a"] = 0;
    }

    void Circuit::set(const std::string& out, const std::string& value) {
        values[out] = getNumericalValue(value);
    }

    valType Circuit::get(const std::string& cable) {
        return values[cable];
    }

    void Circuit::andGate(const std::string& a, const std::string& b,
                const std::string& out) {
        values[out] = getNumericalValue(a) & getNumericalValue(b);
    }

    void Circuit::orGate(const std::string& a, const std::string& b,
            const std::string& out) {
        values[out] = getNumericalValue(a) | getNumericalValue(b);
    }

    void Circuit::notGate(const std::string& in, const std::string& out) {
        values[out] = ~values[in];
    }

    void Circuit::leftShift(const std::string& in, const std::string& shift,
                const std::string& out) {
        values[out] = values[in] << getNumericalValue(shift);
    }

    void Circuit::rightShift(const std::string& in, const std::string& shift,
                const std::string& out) {
        values[out] = values[in] >> getNumericalValue(shift);
    }

    valType Circuit::getNumericalValue(const std::string& in) {
        try {
            return (valType)std::stoi(in);
        } catch (...) {
            return values[in];
        }
    }

    void Circuit::print() {
        for (const auto &pair : values) {
            std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
    }

    operations getElements(const std::string &in, std::string *out) {
        std::regex rgx("^(.+) -> (.+)$");
        std::regex set("^([0-9a-z]+)$");
        std::regex andR("^([a-z0-9]+) AND ([a-z0-9]+)$");
        std::regex orR("^([a-z0-9]+) OR ([a-z0-9]+)$");
        std::regex lshift("^([a-z]+) LSHIFT ([0-9]+)$");
        std::regex rshift("^([a-z]+) RSHIFT ([0-9]+)$");
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
        if (std::regex_match(first_match, input, notR)) {
            out[0] = input[1];
            out[1] = output;
            return operations::notGate;
        }
        if (std::regex_match(first_match, input, andR)) {
            out[0] = input[1];
            out[1] = input[2];
            out[2] = output;
            return operations::andGate;
        }
        if (std::regex_match(first_match, input, orR)) {
            out[0] = input[1];
            out[1] = input[2];
            out[2] = output;
            return operations::orGate;
        }
        if (std::regex_match(first_match, input, lshift)) {
            out[0] = input[1];
            out[1] = input[2];
            out[2] = output;
            return operations::leftShift;
        }
        if (std::regex_match(first_match, input, rshift)) {
            out[0] = input[1];
            out[1] = input[2];
            out[2] = output;
            return operations::rightShift;
        }
        std::cout << in << std::endl;
        std::cout << "SOMETHING WENT WRONG\n";
        throw -1;
    }
}
