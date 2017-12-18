#ifndef FISH_HPP
#define FISH_HPP

#include "item.hpp"

class Fish : public Item
{
public:
        Fish(string s = "Fish");
        ~Fish();
};

#endif
