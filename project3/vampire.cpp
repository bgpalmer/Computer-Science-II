/*********************************************************************
** Program Filename: vampire.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Vampire function definitions
** Input: none
** Output: none
*********************************************************************/

#include "vampire.hpp"

/*********************************************************************
** Function: defend(int attack)
** Description: overrided defend attack specific to derived class
** Parameters: int
** Pre-Conditions: Creature attacks
** Post-Conditions: post
** Return: none
*********************************************************************/

void Vampire::defend(int attack)
{
        // if true, the creature was Glared at by Medusa!
        if (attack == -1)
        {
                // reduce health to zero by subtract strength points from itself
                reduce_str_pts(str_pts);
        }
        // otherwise, maybe take damage
        else
        {
                // vampire maybe charms opponent into doing no damage
                int chance = getRandomPosInt(2);
                if (chance == 0)
                {
                        cout << get_type() << " charms their opponent into not attacking!" << endl;
                        cout << get_type() << " loses no points and currently has " << str_pts << endl;
                }
                // otherwise, takes damage
                else
                {
                        cout << get_type() << " tries to defend itself/himself!\n";
                        int counter = 0;
                        int defense = 0;
                        while (counter < num_def_die)
                        {
                                int roll = def_die->roll();
                                defense += roll;
                                cout << "\t Rolls a " << roll << "!\n";
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

}


/*********************************************************************
** Function: Constructor
** Description: Vampire Constructor
** Parameters: string, int, int ,int ,int ,int ,int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Vampire::Vampire(string type, int armor, int str_pts, int num_a_die, int num_d_die, int num_atk_sides, int num_def_sides) :
 Creature(type, armor, str_pts, num_a_die, num_d_die, num_atk_sides, num_def_sides)
{
         //intentionally blank
}


/*********************************************************************
** Function: destructor
** Description: Vampire Destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/
Vampire::~Vampire()
{
        // intentionally blank
}
