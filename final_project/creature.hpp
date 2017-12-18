#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "validation.hpp"
#include "dice.hpp"

class Space;

class Creature
{
protected:
        string type;
        int health;
        Space * curr_space;
        int atk_pts;
        int def_pts;

public:
        //Space * get_curr_space();
        //virtual int attack() = 0;
        //virtual void turn() = 0;
        void defend(int);

        Creature(string,int,int,int,Space *);
        virtual ~Creature();
};

#endif
