/*********************************************************************
** Program Filename: medusa.hpp
** Author: Brian Palmer
** Date: 11.5.16
** Description: Medusa creature-derived class
** Input: none
** Output: none
*********************************************************************/

#ifndef MEDUSA
#define MEDUSA

#include "creature.hpp"

class Medusa : public Creature
{
public:
        virtual int attack();

        Medusa(string type = "Medusa", int armor = 3, int str_pts = 8, int num_a_die = 2, int num_d_die = 1, int num_atk_sides = 6, int num_def_sides = 6);
        virtual ~Medusa();

};

#endif
