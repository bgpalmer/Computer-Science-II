/*********************************************************************
** Program Filename: blue_men.hpp
** Author: Brian Palmer
** Date: 11.5.16
** Description: Blue Men creature-derived class
** Input: none
** Output: none
*********************************************************************/

#ifndef BLUE
#define BLUE

#include "creature.hpp"

class Blue_Men : public Creature
{
public:
        Blue_Men(string t = "Blue Men", int armor = 3, int str_pts = 12, int num_a_die = 2, int num_d_die = 3, int num_atk_sides = 10, int num_def_sides = 6);
        virtual ~Blue_Men();

        virtual void defend(int);
};

#endif
