/*********************************************************************
** Program Filename: machine.hpp
** Author: brian palmer
** Date: 11.30.16
** Description: Machine class header
** Input: none
** Output: none
*********************************************************************/

#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <string>
#include "item.hpp"
#include "stack.hpp"
using std::string;

class Machine
{
protected:
        string type;
        bool state;
public:
        bool get_state();
        void change_state();
        string get_type();
        virtual void start(Stack *) = 0;

        Machine(string n);
        virtual ~Machine();
};

#endif
