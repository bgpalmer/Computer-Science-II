#include "plant.hpp"

Plant::Plant(string n) : Item(n)
{
        ripe = false;
}

Plant::~Plant()
{
        // intentionally blank
}

bool Plant::get_ripe()
{
        return ripe;
}
