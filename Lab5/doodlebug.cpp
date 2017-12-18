#include "doodlebug.hpp"


void Doodlebug::move()
{
        if (moved == false)
        {
                cout << "number of ants: " << num_ants << endl;
                if (num_ants == 0)
                {
                        // there aren't any ants around so we'll look for an open space instead
                        cout << "number of empties: " << num_empties << endl;
                        if (num_empties == 0)

                                moved = false;
                        else
                        {
                                int random = getRandomPosInt(num_empties);
                                *(empties[random]) = this;
                                moved = true;
                                death_counter++;
                        }
                }
                else
                {
                        // there is at least one ant near by!
                        int random = getRandomPosInt(num_ants);
                        delete *(ants[random]);
                        *(ants[random]) = this;
                        death_counter = 0;
                        moved = true;
                        cout << "** MUNCH MUNCH MUNCH ** " << endl;
                }
        }

}

void Doodlebug::starve()
{
        if (death_counter == DEATH_THRESHOLD)
        {
                delete *current_position;
                *current_position = NULL;
                cout << "a doodlebug starved!" << endl;
        }
}

Doodlebug::Doodlebug(char d) : Critter(d)
{

}

Doodlebug::~Doodlebug()
{
        //intentionally blank
}

void Doodlebug::generate_critter(Critter ** d)
{
        *d = new Doodlebug;
        moved = false;
}
