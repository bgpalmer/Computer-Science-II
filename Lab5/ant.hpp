/*********************************************************************
** Program Filename: ant.hpp
** Author: brian palmer
** Date: 10.24.16
** Description: derived ant class from critter class
** Input: none
** Output: none
*********************************************************************/

#ifndef _ANT
#define _ANT
#include "critter.hpp"

class Ant : public Critter
{
private:
        const int BREED_COUNTER = 3;

        /* helper functions */
        virtual void generate_critter(Critter **);


public:
        virtual void move();
        Ant(char c = 'A');
        virtual ~Ant();
        virtual void starve();
};

#endif
