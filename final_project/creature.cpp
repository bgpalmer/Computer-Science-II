#include "creature.hpp"

Creature::Creature(string t, int a, int d, int h, Space * c)
{
        type = t;
        atk_pts = a;
        def_pts = d;
        health = h;
        curr_space = c;
}

Creature::~Creature()
{
        // intentionally blank
}

Space * Creature::get_curr_space()
{
        return curr_space;
}
