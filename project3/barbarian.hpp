/*********************************************************************
** Program Filename: barbarian.hpp
** Author: Brian Palmer
** Date: 11.5.16
** Description: Barbarian creature-derived class
** Input: none
** Output: none
*********************************************************************/

#ifndef BARBARIAN
#define BARBARIAN

#include "creature.hpp"

class Barbarian : public Creature
{
public:
        Barbarian(string type = "Barbarian", int armor = 0, int str_pts = 12, int num_a_die = 2, int num_d_die = 6, int num_atk_sides = 2, int num_def_sides = 6);
        virtual ~Barbarian();
};

#endif
