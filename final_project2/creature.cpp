/*********************************************************************
** Program Filename: creature.cpp
** Author: brian palmer
** Date: 11.28.16
** Description: Conveyor_Belt function definitions
** Input: none
** Output: none
*********************************************************************/

#include "creature.hpp"

/*********************************************************************
** Function: Creature constructor
** Description: Creature constructor
** Parameters: string, space pointer
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Creature::Creature(string n, Space * c)
{
        type = n;
        curr_space = c;
}

/*********************************************************************
** Function: Creature destructor
** Description: Creature destructor
** Parameters: item pointer
** Pre-Conditions: should be used when constructing the game
** Post-Conditions: none
** Return: none
*********************************************************************/

Creature::~Creature()
{
        // intentionally blank
}

/*********************************************************************
** Function: get type
** Description: returns string
** Parameters: void
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

string Creature::get_type()
{
        return type;
}

/*********************************************************************
** Function: get_curr_space()
** Description: returns pointer to space object curr space is pointing to
** Parameters: void
** Pre-Conditions: World shuold be created first
** Post-Conditions: none
** Return: Space pointer
*********************************************************************/

Space * Creature::get_curr_space()
{
        return curr_space;
}

/*********************************************************************
** Function: set_curr_space
** Description: passes and assigns pointer to creatures curr_space member
** Parameters: item pointer
** Pre-Conditions: should be used when constructing the game
** Post-Conditions: none
** Return: none
*********************************************************************/

void Creature::set_curr_space(Space * space)
{
        curr_space = NULL;
        curr_space = space;
}
