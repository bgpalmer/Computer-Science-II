/*********************************************************************
** Program Filename: critter.cpp
** Author: brian palmer
** Date: 10.24.16
** Description: critter implemetations
** Input: none
** Output: none
*********************************************************************/

#include "critter.hpp"

bool Critter::get_moved() const
{
        return moved;
}

/*********************************************************************
** Function: Constructor
** Description: Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*********************************************************************/

Critter::Critter(char c)
{
        who_am_i = c;
        death_counter = 0;
        breed_counter = 0;
}

/*********************************************************************
** Function: Destructor
** Description: Destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
** Return: None
*********************************************************************/

Critter::~Critter() {}




/*********************************************************************
** Function: update_step_counter
** Description:
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: direction
*********************************************************************/

void Critter::update_breed_counter()
{
        if (moved)
                breed_counter++;
}

char Critter::get_who_am_i() const
{
        return who_am_i;
}

Critter * Critter::deref_once(Critter ** address) const
{
        return *address;
}
/*********************************************************************
** Function: Breed
** Description: possibly creates new ant
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: void
*********************************************************************/

void Critter::breed()
{

}

void Critter::reset_neighborhood()
{
        for (int i = 0; i < num_ants; i++)
        {
                ants = NULL;
        }
        ants = NULL;
        *current_position = NULL;
}

void Critter::set_ants(int r, int c, int rows, int cols, Critter *** f)
{
        int counter = 0;
        if (r - 1 >= 0 && f[r-1][c] != NULL && f[r-1][c]->get_who_am_i() == 'A')
                counter++;
        if (r + 1 < rows && f[r+1][c] != NULL && f[r+1][c]->get_who_am_i() == 'A')
                counter++;
        if (c - 1 >= 0 && f[r][c-1] != NULL && f[r][c-1]->get_who_am_i() == 'A')
                counter++;
        if (c + 1 < cols && f[r][c+1] != NULL && f[r][c+1]->get_who_am_i() == 'A')
                counter++;
        num_ants = counter;
        ants = new Critter ** [counter];
        int spot = 0;

        if (r - 1 >= 0 && f[r-1][c] != NULL && f[r-1][c]->get_who_am_i() == 'A')
        {
                ants[spot] = (&f[r-1][c]);
                spot++;
        }
        if (r + 1 < rows && f[r+1][c] != NULL && f[r+1][c]->get_who_am_i() == 'A')
        {
                ants[spot] = (&f[r+1][c]);
                spot++;
        }
        if (c - 1 >= 0 && f[r][c-1] != NULL && f[r][c-1]->get_who_am_i() == 'A')
        {
                ants[spot] = (&f[r][c-1]);
                spot++;
        }
        if (c + 1 < cols && f[r][c+1] != NULL && f[r][c+1]->get_who_am_i() == 'A')
        {
                ants[spot] = (&f[r][c+1]);
                spot++;
        }

}

void Critter::set_empties(int r, int c, int rows, int cols, Critter *** f)
{

        int counter = 0;
        if (r - 1 >= 0 && f[r-1][c] == NULL)
                counter++;
        if (r + 1 < rows && f[r+1][c] == NULL)
                counter++;
        if (c - 1 >= 0 && f[r][c-1] == NULL)
                counter++;
        if (c + 1 < cols && f[r][c+1] == NULL)
                counter++;
        num_empties = counter;
        empties = new Critter ** [counter];
        int spot = 0;

        if (r - 1 >= 0 && f[r-1][c] == NULL)
        {
                empties[spot] = (&f[r-1][c]);
                spot++;
        }
        if (r + 1 < rows && f[r+1][c] == NULL)
        {
                empties[spot] = (&f[r+1][c]);
                spot++;
        }
        if (c - 1 >= 0 && f[r][c-1] == NULL)
        {
                empties[spot] = (&f[r][c-1]);
                spot++;
        }
        if (c + 1 < cols && f[r][c+1] == NULL)
        {
                empties[spot] = (&f[r][c+1]);
                spot++;
        }
}

void Critter::print() const
{
        cout << who_am_i;
}

void Critter::set_neighborhood(int r, int c, int rows, int cols, Critter *** f)
{
        set_empties(r,c,rows,cols,f);
        set_ants(r,c,rows,cols,f);
        current_position = &f[r][c];
}

void Critter::set_moved(bool b)
{
        moved = b;
}
