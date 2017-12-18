#include "truck.hpp"

Truck::Truck(string n) : Machine(n)
{
        battery = NULL;
}

Truck::~Truck()
{
        delete battery;
}
