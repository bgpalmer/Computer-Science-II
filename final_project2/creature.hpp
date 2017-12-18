/*********************************************************************
** Program Filename: creature.hpp
** Author: brian palmer
** Date: 11.28.16
** Description: Conveyor_Belt class template
** Input: none
** Output: none
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include "space.hpp"
using std::string;

class Creature
{
protected:
        string type;
        Space * curr_space;

public:
        string get_type();
        Space * get_curr_space();
        void set_curr_space(Space *);

        Creature(string n, Space *);
        ~Creature();

        virtual void turn() = 0;
};

#endif
