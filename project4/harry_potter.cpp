/*********************************************************************
** Program Filename: harry_potter.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Harry Potter function definitions
** Input: none
** Output: none
*********************************************************************/

#include "harry_potter.hpp"

/*********************************************************************
** Function: Constructor()
** Description: medusa constructor
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Harry_Potter::Harry_Potter(string type, int armor, int str_pts, int num_a_die, int num_d_die, int num_atk_sides, int num_def_sides) :
 Creature(type, armor, str_pts, num_a_die, num_d_die, num_atk_sides, num_def_sides)
{
        second_life = true;
}

/*********************************************************************
** Function: Destructor()
** Description: Harry_Potter constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Harry_Potter::~Harry_Potter()
{
        // intentionally blank
}

/*********************************************************************
** Function: reduce_str_pts()
** Description: in addition to reducing strength point, adds 20 strength points
to harry potter if he faints and a second life (second_life member)
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Harry_Potter::reduce_str_pts(int damage)
{
        str_pts -= damage;
        cout << get_type() << " takes " << damage << " damage";
        if (str_pts < 0)
        {
                str_pts = 0;
        }
        cout << " and has " << str_pts << " strength points left." << endl;
        if (str_pts == 0 && second_life == true)
        {
                str_pts = 20;
                cout << "HOGWARTS has " << get_type() << "\'s back! He is REVIVED and has " << str_pts << " strength points!" << endl;
                second_life = false;
        }
}
