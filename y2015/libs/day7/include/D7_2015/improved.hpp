#ifndef IMPROVED_HPP
#define IMPROVED_HPP

#include "day7.hpp"
#include <optional>
#include <string>
#include <gtest/gtest.h>

namespace d7i {
    typedef unsigned short valType;

    class Gate {
    protected:
        int priority;
        std::string a_name;
        bool a_set;
        valType a;
        std::string out;
        void setA();
        bool oneEntry;
    public:
        Gate(const std::string& a, const std::string& out);
        Gate();
        bool getType();
        void setA(valType val);
        std::string getA();
        virtual void setB(valType val);
        virtual std::string getB();
        std::string getOut();
        virtual std::optional<valType> execute();
        bool operator>(const Gate& left) const;
        bool operator>=(const Gate& left) const;
    };

    class SetGate: public Gate {
    public:
        SetGate(const std::string& a, const std::string& out);
        SetGate();
        std::optional<valType> execute() override;
    };

    class NotGate: public Gate {
    public:
        NotGate(const std::string& a, const std::string& out);
        NotGate();
        std::optional<valType> execute() override;
    };

    class ComplexGate: public Gate {
    protected:
        std::string b_name;
        bool b_set;
        valType b;
        void setB();
    public:
        ComplexGate(const std::string& a, const std::string& b,
                const std::string& out);
        ComplexGate();
        void setB(valType val) override;
        std::string getB() override;
    };

    class AndGate: public ComplexGate {
    public:
        AndGate(const std::string& a, const std::string& b,
                const std::string& out);
        AndGate();
        std::optional<valType> execute() override;
    };

    class OrGate: public ComplexGate {
    public:
        OrGate(const std::string& a, const std::string& b,
                const std::string& out);
        OrGate();
        std::optional<valType> execute() override;
    };

    class LeftShift: public ComplexGate {
    public:
        LeftShift(const std::string& a, const std::string& b,
                const std::string& out);
        LeftShift();
        std::optional<valType> execute() override;
    };

    class RightShift: public ComplexGate {
    public:
        RightShift(const std::string& a, const std::string& b,
                const std::string& out);
        RightShift();
        std::optional<valType> execute() override;
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
