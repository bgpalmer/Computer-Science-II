/*********************************************************************
** Program Filename: dice.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Dice function definitions
** Input: none
** Output: none
*********************************************************************/

#include "dice.hpp"

/*********************************************************************
** Function: roll()
** Description: Creature constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: positive integer between 0 - num sides
*********************************************************************/

int Dice::roll()
{
        return  1 + getRandomPosInt(num_sides);
}

/*********************************************************************
** Function: Dice()
** Description: Dice constructor
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Dice::Dice(int ns)
{
        num_sides = ns;
}


/*********************************************************************
** Function: Creature()
** Description: Dice destrucotr
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
Dice::~Dice()
{
        // intentionally blank
}
