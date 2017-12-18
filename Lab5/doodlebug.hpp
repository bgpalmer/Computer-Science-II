#ifndef _DOODLE
#define _DOODLE

#include "critter.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Doodlebug : public Critter
{
private:
        const int DEATH_THRESHOLD = 3;
        const int BREED_THRESHOLD = 8;
        virtual void generate_critter(Critter **);
        
public:
        virtual void move();
        virtual void starve();
        virtual ~Doodlebug();
        Doodlebug(char c = 'D');

};

#endif
