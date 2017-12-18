#ifndef PLANT_HPP
#define PLANT_HPP

#include "item.hpp"

class Plant : public Item
{
private:
        bool ripe;
public:
        bool get_ripe();

        Plant(string n = "Plant");
        ~Plant();
};

#endif
