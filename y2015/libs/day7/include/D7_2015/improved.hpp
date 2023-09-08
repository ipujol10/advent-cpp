#ifndef IMPROVED_HPP
#define IMPROVED_HPP

#include <string>

namespace d7i {
    typedef unsigned short valType;

    class Gate {
    protected:
        int priority;
        const std::string in_a;
        bool a_set;
        valType a;
        const std::string out;
    public:
        virtual valType execute() = 0;
    };

    class SetGate: public Gate {
    public:
        valType execute();
    };

    class NotGate: public Gate {
    public:
        valType execute();
    };

    class AndGate: public Gate {
    private:
        const std::string in_b;
        bool b_set;
        valType b;
    public:
        valType execute();
    };

    class OrGate: public Gate {
    private:
        const std::string in_b;
        bool b_set;
        valType b;
    public:
        valType execute();
    };

    class RightShift: public Gate {
    private:
        const std::string in_b;
        bool b_set;
        valType b;
    public:
        valType execute();
    };

    class leftShift: public Gate {
    private:
        const std::string in_b;
        bool b_set;
        valType b;
    public:
        valType execute();
    };

    class MinHeap {
    };
}

#endif // !IMPROVED_HPP
