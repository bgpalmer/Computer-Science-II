/*********************************************************************
** Program Filename: soda_machine.hpp
** Author: brian palmer
** Date: 12.01.16
** Description: soda machine functions
** Input: none
** Output: none
*********************************************************************/

#include "soda_machine.hpp"

/*********************************************************************
** Function: Soda machine constructor
** Description: assigns contents new Queue, then adds 3 sodas to queue
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Soda_Machine::Soda_Machine(string n) : Machine (n)
{
        contents = new Queue;
        contents->push(new Soda);
        contents->push(new Soda);
        contents->push(new Soda);
}

// soda machine destructor

Soda_Machine::~Soda_Machine()
{
        delete contents;
}

/*********************************************************************
** Function: start
** Description: facilitates users actions with the machine
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Soda_Machine::start(Stack * pack)
{
        Item * soda = contents->pop();
        if (soda == NULL)
                cout << "Nothing came out...\n";
        else
        {
                cout << "It is! A free soda! Add to bag?\n";
                char c = facilitateYNresponse();
                switch(c)
                {
                        case 'Y':
                                if (pack->check_weight(soda))
                                        pack->add(soda);
                                break;
                        case 'N':
                                cout << "Eh. Soda's kind of unhealthy\n";
                                cout << "anyways\n";
                                break;
                }

        }
}
