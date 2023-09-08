#include "D7_2015/day7.hpp"
#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <sstream>

namespace d7 {
    Circuit::Circuit() {}

    void Circuit::set(valType in, const std::string& out) {
        values[out] = in;
    }

    valType Circuit::get(const std::string& cable) {
        return values[cable];
    }

    void Circuit::andGate(valType a, valType b, const std::string& out) {
        values[out] = a & b;
    }

    void Circuit::orGate(valType a, valType b, const std::string& out) {
        values[out] = a | b;
    }

    void Circuit::notGate(valType in, const std::string& out) {
        values[out] = ~in;
    }

    void Circuit::leftShift(valType in, valType shift, const std::string& out) {
        values[out] = in << shift;
    }

    void Circuit::rightShift(valType in, valType shift, const std::string& out) {
        values[out] = in >> shift;
    }

    void Circuit::pass() {
        std::string variables[3];
        operations operation;
        std::string a, b, out, line;
        while (!queue.empty()) {
            line = queue.front();
            queue.pop();
            operation = d7::getElements(line, variables);
            switch (operation) {
                case d7::set:
                    a = variables[0];
                    out = variables[1];
                    try {
                        this->set(getNumber(a), out);
                    } catch (...) {
                        queue.push(line);
                    }
                    break;
                case d7::notGate:
                    a = variables[0];
                    out = variables[1];
                    try {
                        this->notGate(getNumber(a), out);
                    } catch (...) {
                        queue.push(line);
                    }
                    break;
                case d7::andGate:
                    a = variables[0], b = variables[1];
                    out = variables[2];
                    try {
                        this->andGate(getNumber(a), getNumber(b), out);
                    } catch (...) {
                        queue.push(line);
                    }
                    break;
                case d7::orGate:
                    a = variables[0], b = variables[1];
                    out = variables[2];
                    try {
                        this->orGate(getNumber(a), getNumber(b), out);
                    } catch (...) {
                        queue.push(line);
                    }
                    break;
                case d7::leftShift:
                    a = variables[0], b = variables[1];
                    out = variables[2];
                    try {
                        this->leftShift(getNumber(a), getNumber(b), out);
                    } catch (...) {
                        queue.push(line);
                    }
                    break;
                case d7::rightShift:
                    a = variables[0], b = variables[1];
                    out = variables[2];
                    try {
                        this->rightShift(getNumber(a), getNumber(b), out);
                    } catch (...) {
                        queue.push(line);
                    }
                    break;
            }
        }
    }
    
    void Circuit::readFromFile(const std::string& file_name) {
        std::string line;
        std::ifstream file(file_name);
        while (std::getline(file, line)) {
            queue.push(line);
        }
    }

    void Circuit::override(const std::string& file_name,
            const std::string& el, valType value) {
        std::string line;
        std::ostringstream ss;
        ss << value;
        std::regex rgx("^[0-9]+ -> " + el + "$");
        std::ifstream file(file_name);
        std::smatch matches;
        while (std::getline(file, line)) {
            if (std::regex_match(line, matches, rgx)) {
                queue.push(ss.str() + " -> " + el);
            } else {
                queue.push(line);
            }
        }
    }

    bool Circuit::exists(const std::string& cable) {
        return values.find(cable) != values.end();
    }

    valType Circuit::getNumber(const std::string& in) {
        try {
            return (valType)std::stoi(in);
        } catch (...) {
            if (exists(in)) {
                return values[in];
            }
            throw -2;
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
