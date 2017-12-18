/*********************************************************************
** Program Filename: insect.hpp
** Author: brian palmer
** Date: 10.24.16
** Description: abstract insect base class
** Input: none
** Output: none
*********************************************************************/

#ifndef _FIELD
#define _FIELD
#include "doodlebug.hpp"
#include "ant.hpp"
#include "critter.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Field
{
private:
        // members
        Critter *** field;
        int cols;
        int rows;
        int turns;
        int num_ants;
        int num_doodlebugs;


        //functions
        void set_neighborhoods();
        void move_critters();
        void breed_critters();
        void doodle_starve(int rows, int cols);
        void reset_move();
        void doodle_starve();


public:
        void set_turns(int);
        void start();
        Field(int turns);
        ~Field();
        // Field(int rows, int cols, int turns)

        virtual void print() const;
};

#endif
