/*********************************************************************
** Program Filename: water.hpp
** Author: brian palmer
** Date: 12.01.16
** Description: water class template
** Input: none
** Output: none
*********************************************************************/

#ifndef WATER_HPP
#define WATER_HPP

#include "item.hpp"

class Water : public Item
{
public:
        Water(string n = "Water", float = 1.50, bool b = false);
        ~Water();

};

#endif
