/*********************************************************************
** Program Filename: creature.hpp
** Author: Brian Palmer
** Date: 11.5.16
** Description: Creature abstract class
** Input: none
** Output: none
*********************************************************************/

#ifndef CREATURE
#define CREATURE

#include "dice.hpp"

class Creature
{
protected:
        int num_atk_die;
        Dice * atk_die;
        int num_def_die;
        Dice * def_die;

        string type;
        int armor;
        int str_pts;

        int armor_effect(int);
        virtual void reduce_str_pts(int);

        int max_str_pts;


public:
        void heal();
        int get_str_pts() const;
        string get_type() const;
        virtual int attack();
        virtual void defend(int);

        Creature(string type, int armor, int str_pts, int num_a_die, int num_d_die, int num_atk_sides, int num_def_sides);
        virtual ~Creature();

};

#endif
