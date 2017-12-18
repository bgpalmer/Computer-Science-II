/*********************************************************************
** Program Filename: item.cpp
** Author: brian palmer
** Date: 11.28.16
** Description: item function definitions
** Input: none
** Output: none
*********************************************************************/

#include "item.hpp"

/*********************************************************************
** Function: item constructor
** Description: item constructor
** Parameters: string, float, bool
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Item::Item(string n, float w, bool s)
{
        type = n;
        weight = w;
        special = s;
}

/*********************************************************************
** Function: item destructor
** Description: item destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
** Return: none
*********************************************************************/

Item::~Item()
{
        // intentionally blank
}


// accessors
float Item::get_weight()
{
        return weight;
}
string Item::get_type()
{
        return type;
}
bool Item::is_special()
{
        return special;
}
