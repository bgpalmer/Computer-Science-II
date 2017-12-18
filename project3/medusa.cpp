/*********************************************************************
** Program Filename: medusa.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Medusa function definitions
** Input: none
** Output: none
*********************************************************************/

#include "medusa.hpp"

/*********************************************************************
** Function: attack()
** Description: creatures attack function
** Parameters:
** Pre-Conditions:
** Post-Conditions:
** Return:
*********************************************************************/

int Medusa::attack()
{
        int counter = 0;
        int attack = 0;
        cout << get_type() << " attacks!\n";
        while (counter < num_atk_die)
        {
                int roll = atk_die->roll();
                cout << "\t" << get_type() << " rolls a " << roll << "!\n";
                attack += roll;
                counter++;
        }
        cout << "\tTotal attack is " << attack << "!\n";
        if (attack == 12)
        {
                attack = -1;
                cout << "Medusa uses GLARE!" << endl;
        }
        return attack;
}

/*********************************************************************
** Function: Constructor()
** Description: medusa constructor
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Medusa::Medusa(string type, int armor, int str_pts, int num_a_die, int num_d_die, int num_atk_sides, int num_def_sides) :
 Creature(type, armor, str_pts, num_a_die, num_d_die, num_atk_sides, num_def_sides)
{
        // intentionally blank
}

/*********************************************************************
** Function: destructor
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Medusa::~Medusa()
{
        // intentionally blank
}
