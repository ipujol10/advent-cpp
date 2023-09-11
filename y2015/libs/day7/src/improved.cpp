#include "D7_2015/improved.hpp"
#include <cstring>
#include <regex>
#include <iostream>

namespace d7i {
    Gate::Gate(const std::string& a,
            const std::string& out): a_name(a), out(out) {
        setA();
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

    bool Gate::getType() {
        return oneEntry;
    }

    void Gate::setA(valType val) {
        a_set = true;
        a = val;
    }

    std::string Gate::getA() {
        return a_name;
    }

    std::string Gate::getOut() {
        return out;
    }

    std::optional<valType> Gate::execute() { return {}; }

    bool Gate::operator>(const Gate& left) const {
        return this->priority > left.priority;
    }

    bool Gate::operator>=(const Gate& left) const {
        return this->priority >= left.priority;
    }

    ComplexGate::ComplexGate(const std::string& a, const std::string& b,
            const std::string& out): Gate(a, out), b_name(b) {
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
            const std::string& out): Gate(a, out) {
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
            const std::string& out): Gate(a, out) {
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

    int MinHeap::parent(int idx) {
        return (idx - 1) / 2;
    }

    int MinHeap::leftChild(int idx) {
        return idx * 2 + 1;
    }

    int MinHeap::rightChild(int idx) {
        return idx * 2 + 2;
    }

    bool MinHeap::isEmpty() {
        return length == 0;
    }
}
