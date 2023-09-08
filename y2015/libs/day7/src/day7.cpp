#include "D7_2015/day7.hpp"
#include <iostream>
#include <regex>
#include <fstream>
#include <string>

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

    void Circuit::pass(const std::string& file_name) {
        std::string line;
        std::ifstream file(file_name);
        std::string variables[3];
        while (std::getline(file, line)) {
            auto operation = d7::getElements(line, variables);
            switch (operation) {
                case d7::operations::set:
                    this->set(variables[1], variables[0]);
                    break;
                case d7::operations::leftShift:
                    this->leftShift(variables[0], variables[1], variables[2]);
                    break;
                case d7::rightShift:
                    this->rightShift(variables[0], variables[1], variables[2]);
                    break;
                case d7::notGate:
                    this->notGate(variables[0], variables[1]);
                    break;
                case d7::andGate:
                    this->andGate(variables[0], variables[1], variables[2]);
                    break;
                case d7::orGate:
                    this->orGate(variables[0], variables[1], variables[2]);
                    break;
            }
        }
    }

    operations getElements(const std::string &in, std::string *out) {
        std::regex set("^([0-9a-z]+) -> ([a-z]+)$");
        std::regex andR("^([a-z0-9]+) AND ([a-z0-9]+) -> ([a-z]+)$");
        std::regex orR("^([a-z0-9]+) OR ([a-z0-9]+) -> ([a-z]+)$");
        std::regex lshift("^([a-z]+) LSHIFT ([0-9]+) -> ([a-z]+)$");
        std::regex rshift("^([a-z]+) RSHIFT ([0-9]+) -> ([a-z]+)$");
        std::regex notR("^NOT ([a-z]+) -> ([a-z]+)$");
        std::smatch matches;

        if (std::regex_match(in, matches, set)) {
            out[0] = matches[1];
            out[1] = matches[2];
            return operations::set;
        }
        if (std::regex_match(in, matches, notR)) {
            out[0] = matches[1];
            out[1] = matches[2];
            return operations::notGate;
        }
        if (std::regex_match(in, matches, andR)) {
            out[0] = matches[1];
            out[1] = matches[2];
            out[2] = matches[3];
            return operations::andGate;
        }
        if (std::regex_match(in, matches, orR)) {
            out[0] = matches[1];
            out[1] = matches[2];
            out[2] = matches[3];
            return operations::orGate;
        }
        if (std::regex_match(in, matches, lshift)) {
            out[0] = matches[1];
            out[1] = matches[2];
            out[2] = matches[3];
            return operations::leftShift;
        }
        if (std::regex_match(in, matches, rshift)) {
            out[0] = matches[1];
            out[1] = matches[2];
            out[2] = matches[3];
            return operations::rightShift;
        }
        std::cout << in << std::endl;
        std::cout << "SOMETHING WENT WRONG\n";
        throw -1;
    }
}
