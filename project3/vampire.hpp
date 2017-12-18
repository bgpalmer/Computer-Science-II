/*********************************************************************
** Program Filename: vampire.hpp
** Author: Brian Palmer
** Date: 11.5.16
** Description: Vampire creature-derived class
** Input: none
** Output: none
*********************************************************************/

#ifndef VAMPIRE
#define VAMPIRE

#include "creature.hpp"

class Vampire : public Creature
{
public:
        virtual void defend(int);

        Vampire(string type = "Vampire", int armor = 1, int str_pts = 18, int num_a_die = 1, int num_d_die = 1, int num_atk_sides = 12, int num_def_sides = 6);
        virtual ~Vampire();
};

#endif
