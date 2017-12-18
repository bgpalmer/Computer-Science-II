#include "von_neurmann_neighborhood.hpp"


// Constructor

Von_Neurmann::Von_Neurmann(Critter ** n, Critter ** s, Critter ** e, Critter ** w, Critter ** cp)
{
        north = n;
        south = s;
        east = e;
        west = w;
        current_pos = cp;
        set_orthogonals();
        set_empties();
        set_ants();

}

// Destructor

Von_Neurmann::~Von_Neurmann()
{
        north = NULL;
        south = NULL;
        east = NULL;
        west = NULL;

        delete [] empties;
        delete [] ants;

        empties = NULL;
        ants = NULL;
}

void Von_Neurmann::set_ants()
{
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
                if (orthogonals[i] != NULL && *(orthogonals[i]) != NULL && (*(orthogonals[i]))->get_who_am_i() == 'A')
                        count++;
        }
        if (count > 0)
        {
                sort_orthogonals();
                ants = new Critter ** [count];
                for (int i = 0; i < count; i++)
                {
                        ants[i] = orthogonals[i];
                }
                num_ants = count;
        }
        else
        {
                num_ants = 0;
                ants = NULL;
        }

}

Critter *** Von_Neurmann::get_ants() const
{
        return ants;
}

int Von_Neurmann::get_num_ants() const
{
        return num_ants;
}

void Von_Neurmann::swap_orthogonals(Critter ** & a, Critter ** & b)
{
        Critter ** temp = b;
        b = a;
        a = temp;
}

void Von_Neurmann::sort_orthogonals()
{
        for (int i = 0; i < 4; i++)
        {
                if (orthogonals[i] == NULL && orthogonals[i+1] != NULL && i + 1 <= 4)
                {
                        swap_orthogonals(orthogonals[i], orthogonals[i+1]);
                }
        }
}

void Von_Neurmann::set_orthogonals()
{
        /* North = 0, South = 1, East = 2, West = 3 */
        orthogonals[0] = north;
        orthogonals[1] = south;
        orthogonals[2] = east;
        orthogonals[3] = west;
}

void Von_Neurmann::set_empties()
{
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
                if (orthogonals[i] != NULL && *(orthogonals[i]) == NULL)
                        count++;
        }
        sort_orthogonals();
        empties = new Critter ** [count];
        for (int i = 0; i < count; i++)
        {
                empties[i] = orthogonals[i];
        }
        num_empties = count;
}

Critter ** const * Von_Neurmann::get_orthogonals() const
{
        return orthogonals;
}

Critter *** Von_Neurmann::get_empties() const
{
        return empties;
}

int Von_Neurmann::get_num_empties() const
{
        return num_empties;
}

Critter ** Von_Neurmann::get_current_pos() const
{
        return current_pos;
}
