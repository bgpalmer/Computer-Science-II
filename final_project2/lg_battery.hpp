#ifndef LARGE_BATTERY_HPP
#define LARGE_BATTERY_HPP

#include "battery.hpp"

class Lg_Battery : public Battery
{
public:
        Lg_Battery(string n, float f);
        ~Lg_Battery();
};

#endif
