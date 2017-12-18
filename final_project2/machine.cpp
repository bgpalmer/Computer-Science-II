/*********************************************************************
** Program Filename: machine.cpp
** Author: brian palmer
** Date: 11.30.16
** Description: machine function definitions
** Input: none
** Output: none
*********************************************************************/

#include "machine.hpp"

// machine constructor
Machine::Machine(string n)
{
        type = n;
        state = false;
}


// machine destructor
Machine::~Machine()
{
        // intentionally blank
}

// type accessor
string Machine::get_type()
{
        return type;
}

// state accessor
bool Machine::get_state()
{
        return state;
}

/*********************************************************************
** Function: change_state
** Description: changes bool value of state member
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Machine::change_state()
{
        if (state == false)
                state = true;
        else
                state = false;
}
