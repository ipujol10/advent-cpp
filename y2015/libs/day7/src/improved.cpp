#include "D7_2015/improved.hpp"
#include <regex>
#include <iostream>

namespace d7i {
    MinHeap::MinHeap(): length(0) {
    }

    void MinHeap::insert(Gate value) {
        data[length] = &value;
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
            return *out;
        }

        data[0] = data[length];
        heapifyDown(0);

        return *out;
    }

    void MinHeap::heapifyDown(int idx) {
        int lIdx = leftChild(idx);
        int rIdx = rightChild(idx);

        if (idx >= length || lIdx >= length) {
            return;
        }

        const auto lV = data[lIdx];
        const auto rV = data[rIdx];
        const auto v = data[idx];

        if (*lV > *rV && *v > *rV) {
            data[idx] = rV;
            data[rIdx] = v;
            heapifyDown(rIdx);
        } else if (*rV > *lV && *v > *lV) {
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
        const auto parentV = data[p];
        const auto v = data[idx];
        if (*parentV > *v) {
            data[idx] = parentV;
            data[p] = v;
            heapifyUp(p);
        }
    }

    int MinHeap::parent(int idx) {
        return (idx - 1) / 2;
    }

    int MinHeap::leftChild(int idx) {
        return idx * 2 + 1;
    }

    int MinHeap::rightChild(int idx) {
        return idx * 2 + 2;
    }

    bool Gate::operator>(const Gate& left) const {
        return this->priority > left.priority;
    }

    Gate::Gate(const std::string& a,
            const std::string& out): in_a(a), out(out), in_b("") {
        executed = false;
    }

    Gate::Gate(const std::string& a, const std::string& b,
            const std::string& out): in_a(a), out(out), in_b(b) {
        executed = false;
    }

    bool Gate::hasBeenExecuted() {
        return executed;
    }

    void Gate::setA() {
        try {
            this->a = (valType)std::stoi(this->in_a);
            this->a_set = true;
        } catch (...) {
            this->a_set = false;
        }
    }

    bool Gate::operator==(const Gate& left) const {
        return this->in_a == left.in_a && this->out == left.out;
    }

    TwoEntries::TwoEntries(const std::string& a, const std::string& b,
                const std::string& out): Gate(a, b, out) {}

    void TwoEntries::setB() {
        try {
            this->b = (valType)std::stoi(this->in_b);
            this->b_set = true;
        } catch (...) {
            this->b_set = false;
        }
    }

    SetGate::SetGate(const std::string& a, 
            const std::string& out): Gate(a, out) {
        priority = 0;
        setA();
    }

    valType SetGate::execute() {
        priority++;
        if (a_set) {
            executed = true;
            return a;
        }
        return 0;
    }

    NotGate::NotGate(const std::string& a, 
            const std::string& out): Gate(a, out) {
        priority = 5;
        setA();
    }

    valType NotGate::execute() {
        priority++;
        if (a_set) {
            executed = true;
            return a;
        }
        return 0;
    }

    RightShift::RightShift(const std::string& a, const std::string& b,
                const std::string& out): TwoEntries(a, b, out) {
        priority = 10;
        setA();
        setB();
    }

    valType RightShift::execute() {
        priority++;
        if(a_set && b_set) {
            executed = true;
            return a >> b;
        }
        return 0;
    }

    LeftShift::LeftShift(const std::string& a, const std::string& b,
                const std::string& out): TwoEntries(a, b, out) {
        priority = 10;
        setA();
        setB();
    }

    valType LeftShift::execute() {
        priority++;
        if(a_set && b_set) {
            executed = true;
            return a << b;
        }
        return 0;
    }

    AndGate::AndGate(const std::string& a, const std::string& b,
                const std::string& out): TwoEntries(a, b, out) {
        priority = 15;
        setA();
        setB();
    }

    valType AndGate::execute() {
        priority++;
        if (a_set && b_set) {
            executed = true;
            return a & b;
        }
        return 0;
    }

    OrGate::OrGate(const std::string& a, const std::string& b,
                const std::string& out): TwoEntries(a, b, out) {
        priority = 15;
        setA();
        setB();
    }

    valType OrGate::execute() {
        priority++;
        if (a_set && b_set) {
            executed = true;
            return a | b;
        }
        return 0;
    }

    valType Gate::execute() { return 0; }

    bool MinHeap::isEmpty() {
        return length == 0;
    }

    Gate MinHeap::translateLine(const std::string& line) {
        std::regex set("^([0-9a-z]+) -> ([a-z]+)$");
        std::regex andR("^([a-z0-9]+) AND ([a-z0-9]+) -> ([a-z]+)$");
        std::regex orR("^([a-z0-9]+) OR ([a-z0-9]+) -> ([a-z]+)$");
        std::regex lshift("^([a-z0-9]+) LSHIFT ([a-z0-9]+) -> ([a-z]+)$");
        std::regex rshift("^([a-z0-9]+) RSHIFT ([a-z0-9]+) -> ([a-z]+)$");
        std::regex notR("^NOT ([a-z0-9]+) -> ([a-z]+)$");
        std::smatch matches;

        if (std::regex_match(line, matches, set)) {
            return SetGate(matches[1], matches[2]);
        }
        if (std::regex_match(line, matches, notR)) {
            return NotGate(matches[1], matches[2]);
        }
        if (std::regex_match(line, matches, andR)) {
            return AndGate(matches[1], matches[2], matches[3]);
        }
        if (std::regex_match(line, matches, orR)) {
            return OrGate(matches[1], matches[2], matches[3]);
        }
        if (std::regex_match(line, matches, lshift)) {
            return LeftShift(matches[1], matches[2], matches[3]);
        }
        if (std::regex_match(line, matches, rshift)) {
            return RightShift(matches[1], matches[2], matches[3]);
        }
        std::cout << line << std::endl;
        std::cout << "SOMETHING WENT WRONG\n";
        throw -1;
    }
}
