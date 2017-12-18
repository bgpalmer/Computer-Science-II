#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "machine.hpp"
#include "lg_battery.hpp"

class Truck : public Machine
{
private:
        Lg_Battery * battery;
public:
        Truck(string n = "Truck");
        ~Truck();
        virtual Item * start();

        bool drive();

};

#endif
