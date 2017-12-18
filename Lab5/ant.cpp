#include "ant.hpp"

void Ant::starve() {}

void Ant::generate_critter(Critter ** address)
{
        moved = false;
        *address = new Ant('A');
}

/*********************************************************************
** Function: move
** Description: moves the ant
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: void
*********************************************************************/

void Ant::move()
{
        if (moved == false)
        {
                if (num_empties == 0)
                {
                        moved = false;
                }
                else
                {
                        int random_num = getRandomPosInt(num_empties);
                        *(empties[random_num]) = this;
                        moved = true;
                        update_breed_counter();
                }
        }
}


/*********************************************************************
** Function: Constructor
** Description: Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*********************************************************************/

Ant::Ant(char c) : Critter(c)
{

}

Ant::~Ant()
{
        // intentionally empty
}
