/*********************************************************************
** Program Filename: office.cpp
** Author: brian palmer
** Date: 12.01.16
** Description: soda class template
** Input: none
** Output: none
*********************************************************************/

#ifndef SODA_HPP
#define SODA_HPP

#include "item.hpp"

class Soda : public Item
{
public:
        Soda(string t = "Soda", float w = 1, bool b = false);
        ~Soda();

};
#endif
