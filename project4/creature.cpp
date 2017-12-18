/*********************************************************************
** Program Filename: creature.cpp
** Author: brian palmer
** Date: 11.5.16
** Description: Creature function definitions
** Input: none
** Output: none
*********************************************************************/

#include "creature.hpp"

// returns type member

string Creature::get_type() const
{
        return type;
}

// returns strength points

int Creature::get_str_pts() const
{
        return str_pts;
}

/*********************************************************************
** Function: attack
** Description: basic attack function for all creatures
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

int Creature::attack()
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
        return attack;
}

/*********************************************************************
** Function: Destructor()
** Description: creature destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: die should be removed successfully
** Return: none
*********************************************************************/

Creature::~Creature()
{
        delete atk_die;
        delete def_die;
}

/*********************************************************************
** Function: Creature()
** Description: Creature constructor
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Creature::Creature(string t, int arm, int strength_pts, int num_a_die, int num_d_die, int num_atk_sides, int num_def_sides)
{
        type = t;
        armor = arm;
        str_pts = strength_pts;
        num_atk_die = num_a_die;
        num_def_die = num_d_die;
        atk_die = new Dice(num_atk_sides);
        def_die = new Dice(num_def_sides);

        max_str_pts = str_pts;
}

/*********************************************************************
** Function: defend(int attack)
** Description: basic defense for all creatures
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

void Creature::defend(int attack)
{
        // if true, the creature was Glared at by Medusa!
        if (attack == -1)
        {
                // reduce health to zero by subtract strength points from itself
                reduce_str_pts(str_pts);
        }
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

/*********************************************************************
** Function: armor_effect()
** Description: armor reduces some of the attack
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: none
** Return: int
*********************************************************************/

int Creature::armor_effect(int attack)
{
        int true_diff = attack - armor;
        int game_diff = true_diff;
        if (game_diff < 0)
                game_diff = 0;
        cout << get_type() << " is wearing armor (" << armor << "), which reduces the attack to " << game_diff << "(" << true_diff << ")"<< endl;
        return game_diff;

}

/*********************************************************************
** Function: reduce_str_pts()
** Description: reduces creatures strength points by parameter.
** Parameters: string, int, int, int, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
** Return: positive integer
*********************************************************************/

void Creature::reduce_str_pts(int damage)
{
        str_pts -= damage;
        cout << get_type() << " takes " << damage << " damage ";
        if (str_pts < 0)
        {
                str_pts = 0;
        }
        cout << "and has " << str_pts << " left." << endl;
}

void Creature::heal()
{
        str_pts += (max_str_pts/4);
        if (str_pts > max_str_pts)
                str_pts = max_str_pts;
        cout << get_type() << "heals a little, and now has " << str_pts << " strength points" << endl;
}
