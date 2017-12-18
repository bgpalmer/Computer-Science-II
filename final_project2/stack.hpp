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
#include <iomanip>
#include "node.hpp"
#include "helper_functions.hpp"

using std::setw;
using std::cout;

class Stack
{
private:
        int num_types;
        //int num_items;
        float weight;
        Node * top;

        Node * find(Item *);

        bool is_empty();

        Node * get_node(int);

public:
        void add(Item *);
        ~Stack();
        Stack();

        bool find(string);
        bool check_weight(Item *);
        bool maybe_add(Item *);
        void display();
        Item * remove(int pos);
        void open();

        void debug();
};

#endif
