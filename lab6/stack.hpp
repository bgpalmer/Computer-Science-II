#ifndef STACK
#define STACK

#include "node.hpp"

class Stack
{
private:
        Node * top;
public:
        ~Stack();
        Stack();
        int pop();
        void push(int);
        bool is_empty();
};

#endif
