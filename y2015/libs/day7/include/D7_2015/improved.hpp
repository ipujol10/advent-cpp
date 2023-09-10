#ifndef IMPROVED_HPP
#define IMPROVED_HPP

#include <string>
#include <gtest/gtest.h>

namespace d7i {
    typedef unsigned short valType;

    class Gate {
    protected:
        int priority;
        const std::string& in_a;
        bool a_set;
        valType a;
        const std::string& out;
        void setA();
    public:
        Gate(const std::string& a, const std::string& out);
        valType execute();
        bool operator>(const Gate& left) const;
        bool operator==(const Gate& left) const;
        FRIEND_TEST(HeapTest, TranslateLine);
        FRIEND_TEST(GateTest, Constructor);
    };

    class OneEntry: public Gate {
    public:
        OneEntry(const std::string& a, const std::string& out);
    };

    class TwoEntries: public Gate {
    protected:
        const std::string& in_b;
        bool b_set;
        valType b;
        void setB();
    public:
        TwoEntries(const std::string& a, const std::string& b,
                const std::string& out);
        bool operator==(const Gate& left) const;
        FRIEND_TEST(GateTest, Constructor);
    };

    class SetGate: public OneEntry {
    public:
        SetGate(const std::string& a, const std::string& out);
        valType execute();
    };

    class NotGate: public OneEntry {
    public:
        NotGate(const std::string& a, const std::string& out);
        valType execute();
    };

    class AndGate: public TwoEntries {
    public:
        AndGate(const std::string& a, const std::string& b,
                const std::string& out);
        valType execute();
    };

    class OrGate: public TwoEntries {
    public:
        OrGate(const std::string& a, const std::string& b,
                const std::string& out);
        valType execute();
    };

    class RightShift: public TwoEntries {
    public:
        RightShift(const std::string& a, const std::string& b,
                const std::string& out);
        valType execute();
    };

    class LeftShift: public TwoEntries {
    public:
        LeftShift(const std::string& a, const std::string& b,
                const std::string& out);
        valType execute();
    };

    class MinHeap {
    private:
        int length;
        Gate *data[400];
        void heapifyDown(int idx);
        void heapifyUp(int idx);
        int parent(int idx);
        int leftChild(int idx);
        int rightChild(int idx);
        Gate translateLine(const std::string& line);
    public:
        MinHeap();
        void insert(Gate value);
        Gate pop();
        bool isEmpty();
        void readFile(const std::string& file_name);
        void readFile(const std::string& file_name, const std::string& cable,
                const std::string& value);
        FRIEND_TEST(HeapTest, TranslateLine);
    };
}

#endif // !IMPROVED_HPP
