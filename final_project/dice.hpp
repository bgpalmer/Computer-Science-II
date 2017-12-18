/*********************************************************************
** Program Filename: Dice.hpp
** Author: Brian Palmer
** Date: 11.5.16
** Description: Dice creature-derived class
** Input: none
** Output: none
*********************************************************************/

#ifndef DICE
#define DICE

#include "helper_functions.hpp"

class Dice
{
private:
        int num_sides;
public:
        int roll();

        Dice(int num_sides);
        ~Dice();

};

#endif
