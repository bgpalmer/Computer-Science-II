/*********************************************************************
** Program Filename: stack.hpp
** Author: brian palmer
** Date: 11.5.16
** Description: stack class
** Input: none
** Output: none
*********************************************************************/

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
        Creature * pop();
        // Creature * peek();
        void push(Creature *);
        bool is_empty();
        void display();
};

#endif
