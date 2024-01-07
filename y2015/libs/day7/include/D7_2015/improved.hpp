#ifndef IMPROVED_HPP
#define IMPROVED_HPP

#include <map>
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
        int getLength();
    };

    class Circuit {
    private:
        std::map<std::string, valType> values;
        MinHeap heap;
        bool exists(const std::string& cable);
        void getElements(const std::string& in);
    public:
        Circuit();
        void readFromFile(const std::string& file_name);
        void readFromFile(const std::string& file_name, const std::string& el,
                valType value);
        void pass();
        std::optional<valType> getNumber(const std::string& cable);
        valType get(const std::string& cable);
        bool isNumber(const std::string& in);
        FRIEND_TEST(CircuitTest, GetElements);
    };
}

#endif // !IMPROVED_HPP
