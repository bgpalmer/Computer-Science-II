/*********************************************************************
** Program Filename: item.hpp
** Author: brian palmer
** Date: 11.28.16
** Description: item class template
** Input: none
** Output: none
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using std::string;

class Item
{
private:
        bool special;
        string type;
        float weight;
public:
        string get_type();
        float get_weight();
        bool is_special();
        Item(string n, float w, bool t);
        ~Item();
};

#endif
