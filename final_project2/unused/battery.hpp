#ifndef BATTERY_HPP
#define BATTERY_HPP

#include "item.hpp"

class Battery : public Item
{
public:
        Battery(string n = "Small Battery", float f = 1.00);
        virtual ~Battery();
};

#endif
