#include "D7_2015/improved.hpp"
#include <cstring>
#include <regex>
#include <iostream>

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
}
