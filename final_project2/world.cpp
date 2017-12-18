/*********************************************************************
** Program Filename: world.cpp
** Author: brian palmer
** Date: 12.01.16
** Description: world class function definitions
** Input: none
** Output: none
*********************************************************************/

#include "world.hpp"


// World Constructor
World::World()
{
        power_plant = new Space ** [2];
        for (int i = 0; i < 2; i++)
                power_plant[i] = new Space * [3];

        power_plant[0][0] = new Office;
        power_plant[0][1] = new Floor;
        power_plant[0][2] = new Bathroom;
        power_plant[1][0] = new Mess_Hall;
        power_plant[1][1] = new Floor;
        power_plant[1][2] = new Loading_Bay;

        for (int i = 0; i < 2; i++)
        {
                for (int j = 0; j < 3; j++)
                        power_plant[i][j]->set_orthogs(power_plant,i,j);
        }
}

// World Destructor
World::~World()
{
        for (int i = 0; i < 2; i++)
        {
                for (int j = 0; j < 3; j++)
                {
                        delete power_plant[i][j];
                }
                delete [] power_plant[i];
        }
        delete [] power_plant;
}

Space *** World::get_power_plant()
{
        return power_plant;
}
