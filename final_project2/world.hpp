/*********************************************************************
** Program Filename: world.hpp
** Author: brian palmer
** Date: 12.01.16
** Description: world class template
** Input: none
** Output: none
*********************************************************************/

#ifndef WORLD_HPP
#define WORLD_HPP
#include "mess_hall.hpp"
#include "office.hpp"
#include "player.hpp"
#include "loading_bay.hpp"
#include "floor.hpp"
#include "bathroom.hpp"

class World
{
private:
        friend class Player;
        Space *** power_plant;
public:
        Space *** get_power_plant();
        World();
        ~World();

};

#endif
