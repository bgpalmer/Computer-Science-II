#ifndef WORLD_HPP
#define WORLD_HPP

#include <iostream>
using std::cout;

#include "field.hpp"
#include "validation.hpp"
#include "town.hpp"
//#include "lake.hpp"



class World
{
private:
        Space * surroundings[6];
        Town * town;
public:
        World();
        ~World();

        Space * get_start_pos();
};

#endif
