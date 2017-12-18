/*********************************************************************
** Program Filename: insect.hpp
** Author: brian palmer
** Date: 10.24.16
** Description: abstract insect base class
** Input: none
** Output: none
*********************************************************************/

#ifndef _CRITTER
#define _CRITTER
#include <string>
#include <iostream>
#include <vector>
#include "validation.hpp"




using std::vector;
using std::cout;
using std::endl;
using std::cin;

using std::string;

class Critter
{
protected:
        // members
        bool moved;
        int death_counter;
        int breed_counter;
        char who_am_i;
        bool breeded;
        Critter *** empties;
        Critter *** ants;
        int num_ants;
        int num_empties;
        Critter ** current_position;

        // helper functions
        void update_breed_counter();
        Critter * deref_once(Critter **) const;
        virtual void set_empties(int, int, int, int, Critter***);
        virtual void set_ants(int,int, int, int, Critter***);

public:
        void breed();
        virtual void move() = 0;
        virtual void generate_critter(Critter **) = 0;
        bool get_moved() const;
        virtual void print() const;
        char get_who_am_i() const;

        void set_moved(bool);
        Critter(char);
        virtual ~Critter();
        virtual void starve() = 0;

        // helpers
        virtual void set_neighborhood(int, int, int, int, Critter ***);
        void reset_neighborhood();

};

#endif
