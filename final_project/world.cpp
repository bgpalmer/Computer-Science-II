#include "world.hpp"

World::World()
{
        town = new Town;
        surroundings[0] = new Field;
        surroundings[1] = new Field;
        surroundings[2] = new Field;
        surroundings[3] = new Field;
        surroundings[4] = new Field;
        surroundings[5] = new Field;

        for (int i = 0; i < 6; i++)
        {
                surroundings[i]->town = town;
                surroundings[i]->clockwise = surroundings[(i+1) % 5];
                surroundings[i]->counter_clockwise = surroundings[(i-1) % 5];
                surroundings[i]->out = NULL;
        }
        town->first = surroundings[0];
        town->second = surroundings[1];
        town->third = surroundings[2];
        town->fourth = surroundings[3];
        town->fifth = surroundings[4];
        town->sixth = surroundings[5];
}

World::~World()
{
        for (int i = 0; i < 6; i++)
        {
                delete surroundings[i];
                surroundings[i] = NULL;
        }
        delete town;
        town = NULL;
}
