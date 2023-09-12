#include "D7_2015/improved.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace d7i {
    Gate::Gate(const std::string& a, const std::string& out,
            gateType type): a_name(a), out(out), type(type) {
        setA();
        oneEntry = true;
        switch (type) {
            case SetGate:
                priority = 0;
                break;
            case NotGate:
                priority = 5;
                break;
            default:
                throw -10;
                break;
        }
    }

    Gate::Gate(const std::string& a,
            const std::string&b,
            const std::string& out,
            gateType type): a_name(a), b_name(b), out(out), type(type) {
        setA();
        setB();
        oneEntry = false;
        switch (type) {
            case LeftShift:
            case RightShift:
                priority = 10;
                break;
            case AndGate:
            case OrGate:
                priority = 15;
                break;
            default:
                throw -10;
                break;
        }
    }

    Gate::Gate() {}

    void Gate::setA() {
        try {
            this->a = (valType)std::stoi(this->a_name);
            this->a_set = true;
        } catch (...) {
            this->a_set = false;
        }
    }

    void Gate::setB() {
        try {
            this->b = (valType)std::stoi(this->b_name);
            this->b_set = true;
        } catch (...) {
            this->b_set = false;
        }
    }

    void Gate::setA(valType val) {
        a_set = true;
        a = val;
    }

    std::string Gate::getA() {
        return a_name;
    }

    void Gate::setB(valType val) {
        b_set = true;
        b = val;
    }

    std::string Gate::getB() {
        return b_name;
    }

    std::string Gate::getOut() {
        return out;
    }

    std::optional<valType> Gate::execute() {
        priority++;
        if (oneEntry && !a_set || (!oneEntry && !(a_set && b_set))) {
            return {};
        }
        switch (type) {
            case SetGate:
                return a;
            case NotGate:
                return ~a;
            case AndGate:
                return a & b;
            case OrGate:
                return a | b;
            case LeftShift:
                return a << b;
            case RightShift:
                return a >> b;
            default:
                return {};
        }
    }

    bool Gate::operator>(const Gate& left) const {
        return this->priority > left.priority;
    }

    bool Gate::operator>=(const Gate& left) const {
        return this->priority >= left.priority;
    }

    bool Gate::isOneEntry() {
        return oneEntry;
    }

    MinHeap::MinHeap(): length(0) {
    }

    void MinHeap::insert(Gate value) {
        data[length] = value;
        heapifyUp(length);
        length++;
    }

    Gate MinHeap::pop() {
        if (length == 0) {
            throw -1;
        }
        const auto out = data[0];
        length--;
        if (length == 0) {
            return out;
        }

        data[0] = data[length];
        heapifyDown(0);

        return out;
    }

    void MinHeap::heapifyDown(int idx) {
        int lIdx = leftChild(idx);
        int rIdx = rightChild(idx);

        if (idx >= length || lIdx >= length) {
            return;
        }

        auto lV = data[lIdx];
        auto rV = data[rIdx];
        auto v = data[idx];

        if (lV >= rV && v > rV) {
            data[idx] = rV;
            data[rIdx] = v;
            heapifyDown(rIdx);
        } else if (rV >= lV && v > lV) {
            data[idx] = lV;
            data[lIdx] = v;
            heapifyDown(lIdx);
        }
    }

    void MinHeap::heapifyUp(int idx) {
        if (idx == 0) {
            return;
        }

        int p = parent(idx);
        auto parentV = data[p];
        auto v = data[idx];
        if (parentV > v) {
            data[idx] = parentV;
            data[p] = v;
            heapifyUp(p);
        }
    }

    int MinHeap::parent(int idx) const {
        return (idx - 1) / 2;
    }

    int MinHeap::leftChild(int idx) const {
        return idx * 2 + 1;
    }

    int MinHeap::rightChild(int idx) const {
        return idx * 2 + 2;
    }

    bool MinHeap::isEmpty() const {
        return length == 0;
    }

    int MinHeap::getLength() {
        return length;
    }

    Circuit::Circuit() {}

    void Circuit::getElements(const std::string& in) {
        std::regex set("^([0-9a-z]+) -> ([a-z]+)$");
        std::regex andR("^([a-z0-9]+) AND ([a-z0-9]+) -> ([a-z]+)$");
        std::regex orR("^([a-z0-9]+) OR ([a-z0-9]+) -> ([a-z]+)$");
        std::regex lshift("^([a-z]+) LSHIFT ([0-9]+) -> ([a-z]+)$");
        std::regex rshift("^([a-z]+) RSHIFT ([0-9]+) -> ([a-z]+)$");
        std::regex notR("^NOT ([a-z]+) -> ([a-z]+)$");
        std::smatch matches;

        if (std::regex_match(in, matches, set)) {
            heap.insert({matches[1], matches[2], SetGate});
        } else if (std::regex_match(in, matches, notR)) {
            heap.insert({matches[1], matches[2], NotGate});
        } else if (std::regex_match(in, matches, andR)) {
            heap.insert({matches[1], matches[2], matches[3], AndGate});
        } else if (std::regex_match(in, matches, orR)) {
            heap.insert({matches[1], matches[2], matches[3], OrGate});
        } else if (std::regex_match(in, matches, lshift)) {
            heap.insert({matches[1], matches[2], matches[3], LeftShift});
        } else if (std::regex_match(in, matches, rshift)) {
            heap.insert({matches[1], matches[2], matches[3], RightShift});
        } else {
            std::cout << in << std::endl;
            std::cout << "SOMETHING WENT WRONG\n";
        }
    }

    bool Circuit::exists(const std::string& cable) {
        return values.find(cable) != values.end();
    }
    
    std::optional<valType> Circuit::getNumber(const std::string& cable) {
        if (!exists(cable)) return {};
        return values[cable];
    }

    void Circuit::readFromFile(const std::string& file_name) {
        std::string line;
        std::ifstream file(file_name);
        while (std::getline(file, line)) {
            getElements(line);
        }
    }

    void Circuit::readFromFile(const std::string& file_name,
            const std::string& el, valType value) {
        std::string line;
        std::ostringstream ss;
        ss << value;
        std::regex rgx("^[0-9]+ -> " + el + "$");
        std::ifstream file(file_name);
        std::smatch matches;
        while (std::getline(file, line)) {
            if (std::regex_match(line, matches, rgx)) {
                getElements(ss.str() + " -> " + el);
            } else {
                getElements(line);
            }
        }
    }

    void Circuit::pass() {
        std::string a, b, out;
        Gate gate;
        while (!heap.isEmpty()) {
            gate = heap.pop();
            a = gate.getA();
            if (exists(a)) {
                gate.setA(values[a]);
            }
            if (!gate.isOneEntry()) {
                b = gate.getB();
                if (exists(b)) {
                    gate.setB(values[b]);
                }
            }
            auto number = gate.execute();
            if (number) {
                values[gate.getOut()] = number.value();
            } else {
                heap.insert(gate);
            }
        }
    }

    valType Circuit::get(const std::string& cable) {
        return values[cable];
    }

    bool Circuit::isNumber(const std::string& in) {
        try {
            (valType)std::stoi(in);
            return true;
        } catch (...) {
            return false;
        }
    }
}
