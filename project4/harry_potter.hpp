/*********************************************************************
** Program Filename: harry_potter.hpp
** Author: Brian Palmer
** Date: 11.5.16
** Description: Harry_Potter creature-derived class
** Input: none
** Output: none
*********************************************************************/

#ifndef HARRYPOTTER
#define HARRYPOTTER

#include "creature.hpp"

class Harry_Potter : public Creature
{
private:
        bool second_life;
protected:
        virtual void reduce_str_pts(int);
public:
        Harry_Potter(string type = "Harry Potter", int armor = 0, int str_pts = 10, int num_a_die = 2, int num_d_die = 2, int num_atk_sides = 6, int num_def_sides = 6);
        virtual ~Harry_Potter();


};

#endif
