#ifndef IMPROVED_HPP
#define IMPROVED_HPP

#include "day7.hpp"
#include <optional>
#include <string>
#include <gtest/gtest.h>

namespace d7i {
    typedef unsigned short valType;

    class BaseGate {
    protected:
        int priority;
        const std::string a_name;
        bool a_set;
        valType a;
        const std::string out;
        void setA();
    public:
        BaseGate(const std::string& a, const std::string& out);
        virtual std::optional<valType> execute();
    };

    class SetGate: public BaseGate {
    public:
        SetGate(const std::string& a, const std::string& out);
        std::optional<valType> execute();
    };

    class NotGate: public BaseGate {
    public:
        std::optional<valType> execute();
    };

    class ComplexGate: public BaseGate {
    protected:
        const std::string b_name;
        bool b_set;
        valType b;
        void setB();
    public:
        ComplexGate(const std::string& a, const std::string& b,
                const std::string& out);
    };

    class AndGate: public ComplexGate {
    public:
        std::optional<valType> execute();
    };

    class OrGate: public ComplexGate {
    public:
        std::optional<valType> execute();
    };

    class LeftShift: public ComplexGate {
    public:
        std::optional<valType> execute();
    };

    class RightShif: public ComplexGate {
    public:
        std::optional<valType> execute();
    };

    enum gateTypes {
        undefined = -1,
        setGate = 0,
        notGate = 1,
        andGate = 2,
        orGate = 3,
        leftShift = 4,
        rightShift = 5
    };

    union GateUnion {
        int undefined;
        SetGate SET;
        NotGate NOT;
        AndGate AND;
        OrGate OR;
        LeftShift LSHIFT;
        RightShif RSHIFT;

        GateUnion(): undefined(-1) {}
    };

    struct Gate {        
        GateUnion gate;
        gateTypes type;
    };

    class MinHeap {
    private:
        int length;
        Gate data[400];
        void heapifyDown(int idx);
        void heapifyUp(int idx);
        int parent(int idx);
        int leftChild(int idx);
        int rightChild(int idx);
    public:
        MinHeap();
        void insert(Gate value);
        Gate pop();
        bool isEmpty();
    };
}

#endif // !IMPROVED_HPP
