/***************
* brian palmer
* 11.29.16
* palmebri@oregonstate.edu
****************/

#ifndef GARDEN_HPP
#define GARDEN_HPP

#include <string>
#include "plant.hpp"

class Garden
{
private:
        Plant * garden[10];
        int size;
public:
        bool plant(Plant *);
        Plant * remove();

        Garden();
        ~Garden();
};

#endif
