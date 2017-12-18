/*********************************************************************
** Program Filename: key.hpp
** Author: brian palmer
** Date: 11.28.16
** Description: key function definitions
** Input: none
** Output: none
*********************************************************************/

#ifndef KEY_HPP
#define KEY_HPP

#include "item.hpp"

class Key : public Item
{
public:
        Key(string n = "Key", float f = 0.00, bool b = true);
        ~Key();
};

#endif
