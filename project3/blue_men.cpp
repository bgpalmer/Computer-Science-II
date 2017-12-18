/*********************************************************************
** Program Filename: blue_men.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Blue Men function definitions
** Input: none
** Output: none
*********************************************************************/

#include "blue_men.hpp"

/*********************************************************************
** Function: Blue Menu()
** Description: Blue Men constructor
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Blue_Men::Blue_Men(string type, int armor, int str_pts, int num_a_die, int num_d_die, int num_atk_sides, int num_def_sides) :
 Creature(type, armor, str_pts, num_a_die, num_d_die, num_atk_sides, num_def_sides)
{
        //intentionally blank
}

/*********************************************************************
** Function: Blue Men()
** Description: Creature Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Blue_Men::~Blue_Men()
{
        // intentionally blank
}

/*********************************************************************
** Function: attack()
** Description: Blue Men overriden attack function
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Blue_Men::defend(int attack)
{
        // if true, the creature was Glared at by Medusa!
        if (attack == -1)
        {
                // reduce health to zero by subtract strength points from itself
                reduce_str_pts(str_pts);
        }
        else
        {
                int counter = 0;
                int defense = 0;
                int num_die = num_def_die - (attack/4);
                if (num_die < 0)
                        num_die = 0;
                cout << get_type() << " roll " << num_die << " die...\n";
                while (counter < num_die)
                {
                        int roll = def_die->roll();
                        defense += roll;
                        cout << "\tRolls a " << roll << "!\n";
                        counter++;
                }
                cout << "\tTotal defense is " << defense << "!\n";
                int true_diff = attack - defense;
                int game_diff = true_diff;
                if (game_diff < 0)
                        game_diff = 0;
                cout << get_type() << " puts up a defense, reducing attack to " << game_diff << "(" << true_diff << ")" << endl;
                game_diff = armor_effect(game_diff);
                cout << get_type() << " loses " << game_diff << " strength points!" << endl;
                reduce_str_pts(game_diff);
        }
}
