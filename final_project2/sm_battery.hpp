#ifndef SMALL_BATTERY
#define SMALL_BATTERY

#include "battery.hpp"

class Sm_Battery : public Battery
{
public:
        Sm_Battery(string n = "Small Battery", float f = 1.50);
        ~Sm_Battery();

};

#endif
