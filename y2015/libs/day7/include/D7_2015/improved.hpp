#ifndef IMPROVED_HPP
#define IMPROVED_HPP

#include "day7.hpp"
#include <optional>
#include <string>
#include <gtest/gtest.h>

namespace d7i {
    typedef unsigned short valType;

    enum gateType {
        SetGate,
        NotGate,
        AndGate,
        OrGate,
        LeftShift,
        RightShift
    };

    class Gate {
    protected:
        int priority;
        std::string a_name;
        bool a_set;
        valType a;
        std::string b_name;
        bool b_set;
        valType b;
        std::string out;
        void setA();
        void setB();
        gateType type;
        bool oneEntry;
    public:
        Gate(const std::string& a, const std::string& out,
                gateType type);
        Gate(const std::string& a, const std::string& b,
                const std::string& out, gateType type);
        Gate();
        void setA(valType val);
        std::string getA();
        void setB(valType val);
        std::string getB();
        std::string getOut();
        std::optional<valType> execute();
        bool operator>(const Gate& left) const;
        bool operator>=(const Gate& left) const;
        bool isOneEntry();
    };

    class MinHeap {
    private:
        int length;
        Gate data[400];
        void heapifyDown(int idx);
        void heapifyUp(int idx);
        int parent(int idx) const;
        int leftChild(int idx) const;
        int rightChild(int idx) const;
    public:
        MinHeap();
        void insert(Gate value);
        Gate pop();
        bool isEmpty() const;
    };
}

#endif // !IMPROVED_HPP
