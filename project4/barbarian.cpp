/*********************************************************************
** Program Filename: barbarian.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Barbarian function definitions
** Input: none
** Output: none
*********************************************************************/

#include "barbarian.hpp"

/*********************************************************************
** Function: Barbarian Constructor
** Description: Barbarian Constructor
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Barbarian::Barbarian(string type, int armor, int str_pts, int num_a_die, int num_d_die, int num_atk_sides, int num_def_sides) :
Creature(type, armor, str_pts, num_a_die, num_d_die, num_atk_sides, num_def_sides)
{
        // intentionally blank
}

/*********************************************************************
** Function: Barbarian Destructor
** Description: Barbarian Destructor
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Barbarian::~Barbarian()
{
        // intentionally blank

}
