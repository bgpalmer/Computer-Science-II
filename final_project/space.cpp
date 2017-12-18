#include "space.hpp"

Space::Space(string n, Space * cw, Space * c_cw, Space * o, Space * t)
{
        town = t;
        clockwise = cw;
        counter_clockwise = c_cw;
        out = o;
        name = n;
        campfire = new Campfire;
}

Space::Space(string a)
{
        town = NULL;
        clockwise = NULL;
        counter_clockwise = NULL;
        out = NULL;
        name = a;
        campfire = new Campfire;
        backpack = new Pack;
}

Space::~Space()
{
        town = NULL;
        clockwise = NULL;
        counter_clockwise = NULL;
        out = NULL;
        delete campfire;
        campfire = NULL;
        delete backpack;
        backpack = NULL;
}

void Space::menu()
{

}

string Space::get_type()
{
        return name;
}

bool Space::light_campfire()
{
        return campfire->light();
}

bool Space::campfire_is_lit()
{
        return campfire->is_lit();
}

Space * Space::get_clockwise()
{
        return clockwise;
}

Space * Space::get_counter_clockwise()
{
        return counter_clockwise;
}

Space * Space::get_town()
{
        return town;
}
