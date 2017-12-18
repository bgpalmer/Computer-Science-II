#ifndef _VON
#define _VON

#include <string>
#include "critter.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;

class Critter;

class Von_Neurmann
{
private:
        //orthogonals
        Critter ** north;
        Critter ** south;
        Critter ** east;
        Critter ** west;

        Critter ** current_pos;

        Critter ** orthogonals[4];
        Critter *** empties;
        Critter *** ants;
        int num_empties;
        int num_ants;

        // helpers
        void set_empties();
        void set_ants();
        void set_orthogonals();
        void sort_orthogonals();
        void swap_orthogonals(Critter ** &, Critter ** &);

public:
        Critter ** get_current_pos() const;
        Critter *** get_empties() const;
        Critter ** const * get_orthogonals() const;
        Critter *** get_ants() const;
        int get_num_empties() const;
        int get_num_ants() const;

        Von_Neurmann(Critter **, Critter **, Critter **, Critter **, Critter **);
        ~Von_Neurmann();
};

#endif
